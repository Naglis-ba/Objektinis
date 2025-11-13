## Įdiegimo Gidas

### Reikalavimai
- CMake 3.15 ar naujesnis

## Įdiegimo Gidas (v1.0 - minimalus pakeitimas)

Šis failas aprašo, kaip sukompiliuoti ir paleisti programą iš šio commit'o, kuris skirtas pateiktiems vertinimo reikalavimams:

- Pilnai veikianti programa v1.0 (šaltinio kodas): `main.cpp`, `funkcijos.cpp`, `funkcijos.h`, `studentas.h`.
- Build konfigūracija: `CMakeLists.txt`.
- Diegimo ir paleidimo instrukcija: šiame faile.
- Tyrimo/aprašymo medžiaga: `README.md` (strategijų tyrimas, lentelės, nuotraukos).

Pastaba: dideli sugeneruoti duomenų failai (`studentai*.txt`, `rez.txt`, `kietiakai.txt`, `vargsiukai.txt`) ir `build/` katalogas nėra įtraukti į commit'ą — jie turi būti laikomi lokaliai arba generuojami pagal poreikį.

cd build

- CMake 3.15+ (rekomenduojama)
- GNU g++ arba kitoks C++17 suderinamas kompiliatorius (g++ 9+ rekomenduojama)
- Linux arba WSL

cmake ..

### Greitas ir patikimas build (rekomenduojamas)
Iš projekto šaknies (kur yra `CMakeLists.txt`):


Arba nurodydami statybos tipą:
```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```

# paleiskite programą
./build/bin/main
```

Ši seka:
- sukuria `build` katalogą (CMake out-of-source build)
- sukonfigūruoja projektą su `Release` tipu (optimizations)
- sugeneruoja binarinį failą `build/bin/main`



### Alternatyva: konfigūracija be `-S/-B`
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j
./bin/main
```

```

### Diegimas (neprivaloma)
Norint įdiegti sistemos ribose (pvz. `/usr/local`):

```bash
make
```

Konkretiems tikslams statyti:
```bash

Po įdiegimo galite pridėti `$HOME/.local/bin` į `PATH` jei pasirinkote vartotojo prefix.

make main                  # Statykite pagrindinę programą

- `main.cpp`, `funkcijos.cpp`, `funkcijos.h`, `studentas.h`
- `CMakeLists.txt`
- `README.md` (turi apimti strategijų tyrimą, lenteles ir nuotraukas)
- `INSTALLATION.md` (šis failas)
- `.gitignore` (sustabdo didelius/automatiškai sugeneruotus failus iš įtraukimo)
- `docs/` arba `assets/` su benchmark nuotraukomis, jeigu naudojate jas README

./bin/main

### Patarimai demonstracijai
- Paruoškite trumpą scenarijų (1-2 komandų seką), kurį parodysite vertintojui:
	1. `mkdir build && cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build -- -j`
	2. `./build/bin/main` (pademonstruokite meniu ir pagrindines funkcijas)

./bin/main

### Troubleshooting

- Jei trūksta `cmake`:
	```bash
	sudo apt install cmake        # Debian/Ubuntu
	sudo dnf install cmake        # Fedora
	```
- Jei trūksta g++:
	```bash
	sudo apt install g++         # Debian/Ubuntu
	```

Jeigu kyla specifinių problemų, aprašykite klaidos tekstą ir aš padėsiu.
```

### Statybos išvestis
- Pagrindinė programa: `bin/main`
- Benchmark'ai: `bin/benchmarks/`
- Dokumentacija: `share/doc/Objektinis/` arba `docs/` po įdiegimo

### Greitas Build ir Paleidimas
```bash
mkdir build && cd build
cmake .. && cmake --build .
./bin/main
```

---

## Troubleshooting

### CMake not found
```bash
# Ubuntu/Debian
sudo apt install cmake

# Fedora/RHEL
sudo dnf install cmake

# macOS (if applicable)
brew install cmake
```

### C++17 compiler not found
```bash
# Ubuntu/Debian
sudo apt install g++-9 # or newer

# Fedora/RHEL
sudo dnf install gcc-c++
```

### Build fails with "cannot find -l"
Make sure all dependencies are installed and you're building from the correct directory.

### Permission denied when installing
Use `sudo` or specify a user-writable prefix:
```bash
cmake --install . --prefix ~/.local
export PATH=$HOME/.local/bin:$PATH
```
