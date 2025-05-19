# Symulator robota sprzątającego

- [English](README.md)

---

## Autorzy
- Weronika Maślana
- Alesia Filinkova
- Katarzyna Kanicka

---

## Opis
Symulator robota sprzątającego w stylu Roomba.
Ten projekt symuluje robota, który wybiera ścieżkę do czyszczenia całego pokoju i wizualizuje proces.

## Użyte języki i biblioteki
- **Języki**: C++
- **System kompilacji**: CMake
- **GUI Framework**: Qt

---

## Mapa drogowa

1. **Konfiguracja początkowa**
   - Konstrukcja obiektów: pokój i meble
   - Konstrukcja obiektu robota
   - Wizualizacja wyświetla robota wewnątrz pomieszczenia

2. **Podstawowe wyznaczanie ścieżek**
   - Implementacja algorytmu ruchu robota
   - Wizualizacja wyświetla ścieżkę i oczyszczone obszary
   - Wizualizacja symuluje ruch robota w pomieszczeniu

3. **Zaawansowane funkcje: Brud, koty i przeszkody**
   - Dodanie algorytmu generowania brudu i czyszczenia
   - Losowe rozmieszczanie mebli i wprowadzenie kotów (ruchome przeszkody)
   - Wdrożenie unikania przeszkód dla robota

4. **Pełna symulacja**
   - Symulacja pomieszczenia z przeszkodami statycznymi (meble) i dynamicznymi (koty)


---

## Obowiązki

1. **Weronika Maślana**  
   - 1.1: Budowa robota  
   - 2.1: Algorytm wyznaczania ścieżki  
   - 3.3: Unikanie przeszkód  

2. **Alesia Filinkova**  
   - 1.2: Budowa pomieszczeń i mebli  
   - 2.2: Wizualizacja ścieżki  
   - 3.1: Algorytm generowania i czyszczenia zabrudzeń  

3. **Katarzyna Kanicka**  
   - 1.3: Implementacja wizualizacji 
   - 2.3: Symulacja ruchu  
   - 3.2: Koty (poruszające się meble)  

---

## Główne obiekty

- **Room** - definiuje wymiary (szerokość, długość) i przechowuje przeszkody  
- **Furniture** - zawiera wymiary i współrzędne  
- **Robot** - ma pozycję początkową i rozmiar; zdolny do odnajdywania ścieżek  
- **Cat** - reprezentuje dynamiczne, ruchome meble z wymiarami i współrzędnymi  

## Komponenty pomocnicze

- **Vizualizer** - wyświetla pomieszczenie, robota, ścieżkę i przeszkody.  
- **Simulation** - konfiguruje pomieszczenie, robota, przeszkody i proces sprzątania.  
- **RoomInfo** - wirtualny rodzic `Room`, może ocenić wolną przestrzeń i bliskość ścian (południe/wschód)  
- **FurnitureGenerator** - losowo generuje meble w pokoju  

---

## Kluczowe metody

- `make_path` - Generuje ścieżkę, ruch odbywa się od lewej do prawej, od góry do dołu.  
- `object_detour` - Nawiguje wokół przeszkody, a następnie powraca do pierwotnej pozycji pionowej.  
- `detour_object_below_next_to_wall` - Obsługuje przypadki, w których robot jest uwięziony i musi się wycofać i spróbować nowej trasy.  
- `move_back_to_check_for_moving_object` - Robot cofa się, aby sprawdzić, czy przeszkoda się poruszyła.  
- `go_to_touch_object` - Zbliża się do obiektu, a następnie cofa się, aż do znalezienia wolnej pozycji.  
- `is_place_free_for_object` - Sprawdza, czy dany obszar jest wolny i czy znajduje się wewnątrz pomieszczenia.  
- `dust` - generuje kurz i wizualizuje go  
