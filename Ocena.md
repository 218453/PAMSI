# Lab2 - tablica dynamiczna

Sposób pomiaru czasu OK.
Nic nie rozumiem ze sprawozdania - brak treści, brak wniosków, wykresy nieczytelne.

Ocena: 3 (sprawozdanie zawiera tylko tabelę z wynikami)

# Lab3 - projektowanie obiektowe

Interfejs IRunnable.
Nic nie rozumiem ze sprawozdania - brak treści, brak wniosków, wykresy nieczytelne.

Ocena: 3 (sprawozdanie zawiera tylko tabelę z wynikami)

# Lab4 - ADT, lista / kolejka / stos

Dlaczego IRunnable nie został wykorzystany do testów kolejki?
Dlaczego kolejka, zadanie mówiło o testach przeszukiwania na liście.

Sprawozdanie pozostawia wiele do życzenia. Dzisiejsze komputery radzą sobie także
z mierzeniem czasu z rozdzielczością lepszą niż "milisekunda", więc nie ma wytłumaczenia
dla braku pomiarów i wykresu. Brak dyskusji złożoności obliczeniowej.

Ocena: 3

# Lab5 - sortowanie
# Lab6 - tablica asocjacyjna

W sprawozdaniu brakuje omówienia kwestii powiększania tablicy dynamicznej, które
jest niezbędne, aby faktycznie osiągnąć złożoność O(1). Współczynnik wypełnienia
musi być utrzymywany na odpowiednim poziomie. Po zmianie rozmiaru tablicy konieczne
jest wykonanie tzw. "rehashowania", czyli przeorganizowania całej tablicy, co wiążę
się z pewnym kosztem, który jednak "amortyzuje się" podobnie jak operacje wykonywane
przy powiększaniu tablicy dynamicznej (przy odpowedniej strategii tego powiększania).

Złożoność obliczeniowa O(n log n) dla operacji wstawiania jest zupełnie niewytłumaczalna,
bo o ile odczyt wiąże się z ewentualnym przeszukaniem listy elementów o jednakowej
wartości funkcji skrótu, o tyle wstawianie jest po prostu dopisaniem elementu do listy,
w związku z tym musi być O(1).

Ocena: 3
