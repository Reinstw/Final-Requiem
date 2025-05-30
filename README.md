# Final-Requiem
Un gioco di ruolo testuale a turni ambientato in un mondo fantasy originale. Esplora 5 aree, affronta boss unici e prendi decisioni che influenzano la storia e la difficoltà.

# 🧿 Valisthea: La Caduta dei Cristalli

**Valisthea: La Caduta dei Cristalli** è un gioco narrativo testuale in C++ ambientato in un mondo fantasy in rovina, in cui il giocatore si mette nei panni di un eroe destinato a distruggere i Cristalli Madre per salvare la terra... o condannarla.

Il gioco combina elementi di **storia interattiva**, **scelte morali**, **battaglie a turni** e **eventi casuali**. Il tutto arricchito da una narrazione immersiva e da effetti visivi attraverso l’utilizzo di **caratteri ANSI colorati** nel terminale.

---

## 🚀 Come Avviare il Gioco

Il gioco può essere eseguito **direttamente da terminale** (anche l'.exe) **senza problemi di visualizzazione dei caratteri** grazie a un’inizializzazione speciale per il supporto UTF-8 e i colori ANSI.

Queste righe sono già **integrate nella build dell’eseguibile** (quindi **NON sono presenti nel file `main.cpp`**, per evitare comportamenti anomali nella console di VS Code):

```cpp
// Imposta la codifica UTF-8 per la console
SetConsoleOutputCP(CP_UTF8);

// Abilita il supporto ai colori ANSI nella console di Windows
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;
GetConsoleMode(hOut, &dwMode);
dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
SetConsoleMode(hOut, dwMode);
```

> ⚠️ Nota: Se copi il codice sorgente in un tuo progetto, **non è consigliato includere le righe sopra direttamente nel `main.cpp` di VS Code**, poiché potrebbero causare comportamenti inaspettati.

---

## 🖥️ Requisiti

- **Sistema operativo:** Windows 10 o superiore
- **Compilatore C++** installato (es. `g++` via `MinGW` o `MSVC`)
- **Visual Studio Code** (o altro IDE che supporta C++ e il terminale integrato)
- **Abilitazione ANSI nel terminale Windows** (automaticamente gestita dall’eseguibile)

> 🔧 Per installare il compilatore, segui la guida ufficiale sul sito di Visual Studio Code:  
> 👉 [https://code.visualstudio.com/docs/languages/cpp](https://code.visualstudio.com/docs/languages/cpp)

---

## 🛠️ Come Compilare e Lanciare

### ✅ Dal Terminale di VS Code:

```bash
g++ -o valisthea.exe main.cpp
./valisthea.exe
```

### ✅ Oppure esegui direttamente l'.exe precompilato (incluso nel repository), purché il compilatore sia installato.

---

## ⚠️ Compatibilità

Il gioco utilizza:

- Librerie moderne di C++ (`<chrono>`, `<conio.h>`, ecc.)
- Codici ANSI per colori e formattazione testuale
- Funzioni specifiche per Windows (`SetConsoleOutputCP`, `GetConsoleMode`, ecc.)

Per questo motivo:

- ❌ Non garantito il funzionamento su ambienti **Dev-C++**, **Code::Blocks** o **compilatori online**
- ✅ Funziona perfettamente su **Visual Studio Code** con **MinGW** o **MSVC**

---

## 🎮 Gameplay

- Naviga tra zone corrotte dalla Brama
- Combatti boss epici legati ai Cristalli Madre
- Fai scelte che influenzano la storia
- Sperimenta eventi casuali e maledizioni
- Conquista (o distruggi) Valisthea

---

## 📸 Screenshot

![screenshot fantasy console](./screenshots/valisthea_preview.png)

---

## 📄 Licenza

Questo gioco è un progetto personale open-source. Può essere modificato, studiato o adattato liberamente con attribuzione.

---

## 👤 Autore

Creato con passione per il fantasy, il codice e la narrazione.

---

> ✨ *“I Cristalli ci hanno dato tutto. Ora tocca a noi decidere se continuare a dipendere da loro... o cambiare il nostro destino.”*
