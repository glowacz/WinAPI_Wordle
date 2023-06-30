# WinAPI_Wordle

Gra Wordle napisana w WinAPI. Posiada 3 poziomy trudności, animację odsłaniania liter i ich kolorowanie (w głównym oknie i oknie z klawiaturą).

Szczegóły (treść zadania przygotowana przez prowadzących przedmiot):

**Layout:**
•	Okno klawiatury wyśrodkowane w poziomie oraz odsunięte w dół, powinno zawsze być widoczne w całości
•	Okna rozgrywki wyśrodkowane do zadanych części ekranu:
o	Jedno okno - na środku ekranu
o	Dwa okna - wyśrodkowane w dwóch połówkach ekranu
o	Cztery okna - wyśrodkowane w czterech ćwiartkach ekranu
•	Stały rozmiar okien rozgrywki zależny od rozmiaru planszy
•	Stały rozmiar okna klawiatury dobrany losowo
•	Ustawiony tytuł "WORDLE - KEYBORD" oraz "WORDLE - PUZZLE" odpowiednio dla okna klawiatury i okien rozgrywki
•	Ustawiona ikonka: "Wordle.ico" (Ikonka powinna być także widoczna w pasku zadań. Wystarczy jak będzie w oknie głównym.)
•	Kolor tła aplikacji: (255, 255, 255)
•	Kolory przycisków (tło literek) o rozmiarze 55 i marginesie między nimi 6:
•	Litera pusta (domyślny kolor) - (251,252,255)
•	Litera niepoprawna - (164, 174, 196)
•	Litera w słowie ale w złym miejscu - (243,194,55)
•	Litera w poprawnym miejscu - (121,184,81)
•	Ramka litery w kolorze przycisku i/lub kolorze niepoprawnym jeśli tła ma domyślny kolor
•	Domyślny rozmiar to 6 słów po 5 liter
•	Rozmiar zmienny zależnie od poziomu trudności (np. Easy 6 słów, Medium 8 słów, Hard 10 słów)
•	Aplikacja wczytuje dostępne słowa z pliku txt
•	Każde okno rozgrywki posiada inne słowo do rozwiązania
•	Litery wpisywane są jednocześnie do wszystkich okien rozgrywki
•	Enter akceptuje słowo, Backspace usuwa literę
•	Słowa zaakceptowanego nie można zmieniać
•	Po akceptacji następuje animacja odkrycia liter w słowie
•	Jeśli słowo została odgadnięte, pojawia się zielony przezroczysty overlay a okno przestaje akceptować nowe litery
•	Jeśli nie odgadliśmy słowa pojawia się czerwony przezroczysty overlay z napisem zawierającym poprawne hasło
•	Litery na klawiaturze kolorowane są natychmiastowo po odgadnięciu (Enter) zależnie od poziomu trudności i rozłożenia okien

**Logika aplikacji:**
•	Okno klawiatury zawsze jest przezroczyste
•	Okno klawiatury wyświetla litery jak na klawiaturze
•	Okno klawiatury i okna rozgrywki kolorują litery zależnie od ich statusu w danym oknie rozgrywki (kilka kolorów dla większe liczby okien rozgrywki)
•	Zmiana poziomu trudności (również na ten sam) powoduje restart rozgrywki i reset okien
•	Enter akceptuje słowo
•	Backspace usuwa literę
•	Wyświetlanie overlay zależnie od statusu gry
•	Zielony - słowo odgadnięte
•	Czerwony z wyświetlonym rozwiązaniem - przegrana
•	Litery odkrywane są przy pomocy animacji
•	Rysowanie okna nie powinno powodować mrugania
•	Wpisywanie liter odbywa się tylko w momencie kiedy okno klawiatury ma focus
•	Aplikacja korzysta z zapisu/wczytania poziomu trudności do/z pliku ini
