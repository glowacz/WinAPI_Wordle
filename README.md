# WinAPI_Wordle

Gra Wordle napisana w WinAPI. Posiada 3 poziomy trudności, animację odsłaniania liter i ich kolorowanie (w głównym oknie i oknie z klawiaturą).

![screen](https://github.com/glowacz/WinAPI_Wordle/assets/94084660/0cad8ea5-2bab-4bc4-827c-18629945835c)

Szczegóły (treść zadania przygotowana przez prowadzących przedmiot):

Layout:
• Okno klawiatury wyśrodkowane w poziomie oraz odsunięte w dół, powinno zawsze być widoczne w całości<br />
• Okna rozgrywki wyśrodkowane do zadanych części ekranu:<br />
o Jedno okno - na środku ekranu<br />
o Dwa okna - wyśrodkowane w dwóch połówkach ekranu<br />
o Cztery okna - wyśrodkowane w czterech ćwiartkach ekranu<br />
• Stały rozmiar okien rozgrywki zależny od rozmiaru planszy<br />
• Stały rozmiar okna klawiatury dobrany losowo<br />
• Ustawiony tytuł "WORDLE - KEYBORD" oraz "WORDLE - PUZZLE" odpowiednio dla okna klawiatury i okien rozgrywki<br />
• Ustawiona ikonka: "Wordle.ico" (Ikonka powinna być także widoczna w pasku zadań. Wystarczy jak będzie w oknie głównym.)<br />
• Kolor tła aplikacji: (255, 255, 255)<br />
• Kolory przycisków (tło literek) o rozmiarze 55 i marginesie między nimi 6:<br />
• Litera pusta (domyślny kolor) - (251,252,255)<br />
• Litera niepoprawna - (164, 174, 196)<br />
• Litera w słowie ale w złym miejscu - (243,194,55)<br />
• Litera w poprawnym miejscu - (121,184,81)<br />
• Ramka litery w kolorze przycisku i/lub kolorze niepoprawnym jeśli tła ma domyślny kolor<br />
• Domyślny rozmiar to 6 słów po 5 liter<br />
• Rozmiar zmienny zależnie od poziomu trudności (np. Easy 6 słów, Medium 8 słów, Hard 10 słów)<br />
• Aplikacja wczytuje dostępne słowa z pliku txt<br />
• Każde okno rozgrywki posiada inne słowo do rozwiązania<br />
• Litery wpisywane są jednocześnie do wszystkich okien rozgrywki<br />
• Enter akceptuje słowo, Backspace usuwa literę<br />
• Słowa zaakceptowanego nie można zmieniać<br />
• Po akceptacji następuje animacja odkrycia liter w słowie<br />
• Jeśli słowo została odgadnięte, pojawia się zielony przezroczysty overlay a okno przestaje akceptować nowe litery<br />
• Jeśli nie odgadliśmy słowa pojawia się czerwony przezroczysty overlay z napisem zawierającym poprawne hasło<br />
• Litery na klawiaturze kolorowane są natychmiastowo po odgadnięciu (Enter) zależnie od poziomu trudności i rozłożenia okien

Logika aplikacji:
• Okno klawiatury zawsze jest przezroczyste<br />
• Okno klawiatury wyświetla litery jak na klawiaturze<br />
• Okno klawiatury i okna rozgrywki kolorują litery zależnie od ich statusu w danym oknie rozgrywki (kilka kolorów dla większe liczby okien rozgrywki)<br />
• Zmiana poziomu trudności (również na ten sam) powoduje restart rozgrywki i reset okien<br />
• Enter akceptuje słowo<br />
• Backspace usuwa literę<br />
• Wyświetlanie overlay zależnie od statusu gry<br />
• Zielony - słowo odgadnięte<br />
• Czerwony z wyświetlonym rozwiązaniem - przegrana<br />
•	Litery odkrywane są przy pomocy animacji<br />
•	Rysowanie okna nie powinno powodować mrugania<br />
•	Wpisywanie liter odbywa się tylko w momencie kiedy okno klawiatury ma focus<br />
•	Aplikacja korzysta z zapisu/wczytania poziomu trudności do/z pliku ini<br />
