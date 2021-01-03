## Bowling 🎳

### Wymagania:

* liczenie punktów cząstkowych (dla niepełnych ramek, np: `3-|X|4/|5`)
* liczenie punktów całościowych - [opis zasad](https://github.com/coders-school/testing/blob/master/module2/bowling_rules.txt)
* walidacja inputu z niepełnymi ramkami dla kilku graczy (patrz następny slajd)
* input z wielu plików w jednym katalogu, każdy plik z kilkoma graczami reprezentuje inny tor (zalecane użycie [Filesystem library z C++17](https://en.cppreference.com/w/cpp/filesystem))
* wyświetlanie wyników na ekranie z podziałem na tory (ze statusem gry) i graczy oraz zapis do jednego pliku (następny slajd)
* program (`main.cpp`) ma przyjmować 2 parametry z linii komend. Pierwszy to katalog, w którym będą pliki txt ze stanami gier na torach, a drugi opcjonalny to plik wyjściowy, w którym mają zostać zapisane przetworzone wyniki. Jeśli drugi parametr nie zostanie podany to wyniki mają zostać wypisane na ekran. Przykład użycia: `./bowling inputDirectory results.txt`. Program oczywiście ma działać i realizować powierzone zadanie.
* program (`main.cpp`) po podaniu parametru `-h` lub `--help` ma wyświetlać krótką informację o tym co robi i jak go używać (czyli punkt powyżej)

___

### Bowling - input

`lane1.txt`

```text
Name1:X|4-|3
Name2:34|X|0-
:X|22|33
```

`lane2.txt` (pusty)

`lane3.txt`

```text
Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81
Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||
```

### Bowling - output

```text
### Lane 1: game in progress ###
Name1 30
Name2 44
34
### Lane 2: no game ###
### Lane 3: game finished ###
Michael 167
Radek 90
```
