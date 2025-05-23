#include "room.h"

Room::Room(std::vector <int> room_size) : room_size(room_size) {
    is_valid();
}

void Room::is_valid() {
    if (room_size.size() != 2) {
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of size. Must be 2 (x, y). Given " << room_size.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if (room_size[0] <= 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid room length " << room_size[0];
        throw std::invalid_argument(exeption_str.str());
    }
    if (room_size[1] <= 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid room width " << room_size[1];
        throw std::invalid_argument(exeption_str.str());
    }
}
bool Room::is_place_free_for_object(const std::vector<int>& coordinates, const std::vector<int>& size) const{
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            if (coordinates[0] + i < 0 || coordinates[0] + i > room_size[0] || coordinates[1] + j < 0 || coordinates[1] + j > room_size[1]) {
                return false;
            }
            const std::vector<int> current_coordinate = { coordinates[0] + i, coordinates[1] + j };
            for (size_t k = 0; k < taken_places.size(); k++) {
                if (taken_places[k] == current_coordinate) {
                    return false;
                }
            }
        };
    };
    return true;
}


void Room::setLength(int length) {
    if (length > 0) {
        this->room_size[0] = length;
    }
    else {
        std::cerr << "Error: wrong length" << std::endl;
    }
}

void Room::setWidth(int width) {
    if (width > 0) {
        this->room_size[1] = width;
    }
    else {
        std::cerr << "Error: wrong width" << std::endl;
    }
}

void Room::addCoordinates(const Furniture& f) {
    auto coordinates = f.get_coordinates();
    int x = coordinates[0];
    int y = coordinates[1];
    int length = f.getLength();
    int width = f.getWidth();
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            taken_places.push_back({ x + i, y + j });
        }
    }
}

void Room::deleteCoordinates(const Furniture& f) {
    for (int i = 0; i <= f.getLength() - 1; i++)
    {
        for (int j = 0; j <= f.getWidth() - 1; j++)
        {
            std::vector<int> coordinate = { f.get_coordinates()[0] + i, f.get_coordinates()[1] + j };
            for (int g = 0; g < taken_places.size(); g++)
            {
                if (taken_places[g] == coordinate) {
                    taken_places.erase(taken_places.begin() + g);
                }
            }
        }
    }
}


void Room::addFurniture(std::unique_ptr<Furniture> new_furniture) {
    const auto& coordinates = new_furniture->get_coordinates();

    int length = new_furniture->getLength();
    int width = new_furniture->getWidth();

    if (is_place_free_for_object(coordinates, { length, width }) || taken_places.empty()) {
        addCoordinates(*new_furniture);
        furniture.push_back(std::move(new_furniture));
    }
    else {
        std::stringstream exception_str;
        exception_str << "Impossible to place this object: " << new_furniture->getName();
        throw std::invalid_argument(exception_str.str());
    }
}

void Room::deleteFurniture(const std::string& furnitureName) {
    auto furn = std::find_if(furniture.begin(), furniture.end(),
        [&furnitureName](const std::unique_ptr<Furniture>& f) {
            return f->getName() == furnitureName;
        });

    if (furn != furniture.end()) {
        deleteCoordinates(**furn);
        furniture.erase(furn);
    }
}

void Room::dust() {
    srand(time(NULL));
    for (int i = 0; i < (rand() % (getLength() * getWidth())); i++)
    {
        std::vector<int> dust_coordinate = { rand() % getLength(), rand() % getWidth() };
        bool is_area_empty = true;
        for (size_t i = 0; i < taken_places.size(); i++) {
            if (taken_places[i] == dust_coordinate) {
                is_area_empty = false;
            }
        }
        if (is_area_empty) {
            dirty_places.push_back(dust_coordinate);
        }
    }
}

void Room::cleanDirty(std::vector<int> dust) {
    std::vector<std::vector<int>> d = getDirtyPlaces();
    for (auto dirty = d.begin(); dirty != d.end();)
    {
        const std::vector<int>& dust_coordinate = *dirty;
        int x = dust_coordinate[0];
        int y = dust_coordinate[1];
        if (dust[0] == x && dust[1] == y) {
            dirty_places.erase(dirty);
        }
        else {
            ++dirty;
        }
    }
};

void Room::update() {
    srand(time(NULL));
    for (const auto& f : furniture) {
        Cat* cat = dynamic_cast<Cat*>(f.get());

        if (cat) {
            deleteCoordinates(*cat);
            int deltaX = 0, deltaY = 0;
            int direction = rand() % 4;
            switch (direction) {
            case 0: // Up
                deltaY = -5;
                break;
            case 1: // Down
                deltaY = 5;
                break;
            case 2: // Left
                deltaX = -5;
                break;
            case 3: // Right
                deltaX = 5;
                break;
            }
            std::vector<int> new_coordinates = cat->get_coordinates();
            new_coordinates[0] += deltaX;
            new_coordinates[1] += deltaY;

            int length = cat->getLength();
            int width = cat->getWidth();

            if (is_place_free_for_object(new_coordinates, { length, width })) {
                cat->move(deltaX, deltaY);
            }
            else {
                cat->updatePath(cat->get_coordinates());
            }
            addCoordinates(*cat);

        }

    }
}