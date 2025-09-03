
# 🏀 Basketball Player Performance Analyzer

A C-based terminal application for tracking and analyzing basketball player statistics. Useful for sports hobbyists, analysts, or students learning structured programming and file handling in C.

---

### 📋 Features

- Add player stats (points, assists, rebounds, steals, blocks, turnovers)
- Calculate per-game performance metrics
- Compare players to find the top scorer
- Save and load stats from a file
- Update or remove player entries
- Simple menu-driven interface

---

### 🔧 Tech

- **C Programming Language**
- Standard libraries: `stdio.h`, `string.h`

---

### ▶️ How to Compile and Run

1. **Save the file** as `analyzer.c`
2. **Compile it** using GCC:
```bash
gcc analyzer.c -o analyzer
```
3. **Run the executable**:
```bash
./analyzer
```

---

### 📦 Example Stats

When running, you can input:
- Name: `Robert Pattinson`
- Points: `300`
- Games Played: `15`
- And other stat fields

The app then shows per-game metrics like PPG (Points Per Game), APG (Assists), RPG (Rebounds), and simple performance insights.

---

### 📂 File I/O

- `players.txt` is used to store and retrieve player stats.
- Supports persistent storage and updates across sessions.

---
