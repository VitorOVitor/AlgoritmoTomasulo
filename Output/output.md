# CYCLE 1
## Log
* [1] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 2
## Log
* [2] Dispatched
* [1] Started

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 0},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 3
## Log
* [3] Dispatched
* [2] Cannot start, it's waiting for Register R1

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 0},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 4
## Log
* [2] Cannot start, it's waiting for Register R1
* [3] Cannot start, it's waiting for Register R1

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 0},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 5
## Log
* [1] Completed
* [2] Cannot start, it's waiting for Register R1
* [3] Cannot start, it's waiting for Register R1

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 0},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": 5,
        "writtenAt": 6
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 6
## Log
* [1] Wrote to memory
* [2] Started
* [3] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 7
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 8
## Log
* [3] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 6,
        "finishedAt": 8,
        "writtenAt": 9
    }},
]
```
---

# CYCLE 9
## Log
* [3] Wrote to memory

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 10
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 11
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 12
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 13
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CYCLE 14
## Log
* [2] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": 14,
        "writtenAt": 15
    }},
]
```
---

# CYCLE 15
## Log
* [2] Wrote to memory

## Registers
```json
[
]
```

## Stations
```json
[
]
```
---

# CYCLE 1
## Log
* [1] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 2
## Log
* [2] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 3
## Log
* [3] Dispatched
* [2] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 4
## Log
* [3] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 5
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 6
## Log
* [3] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": 6,
        "writtenAt": 7
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 7
## Log
* [3] Wrote to memory

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 8
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 9
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 10
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 11
## Log
* [2] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": 11,
        "writtenAt": 12
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 12
## Log
* [1] Started
* [2] Wrote to memory

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 13
## Log

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 14
## Log

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 15
## Log
* [1] Completed

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": 15,
        "writtenAt": 16
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 16
## Log
* [1] Wrote to memory

## Registers
```json
[
]
```

## Stations
```json
[
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 1
## Log
* [1] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 2
## Log
* [2] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 3
## Log
* [3] Dispatched
* [2] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 4
## Log
* [3] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 5
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 6
## Log
* [3] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": 6,
        "writtenAt": 7
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 7
## Log
* [3] Wrote to memory

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 8
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 9
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 10
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 11
## Log
* [2] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": 11,
        "writtenAt": 12
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 12
## Log
* [1] Started
* [2] Wrote to memory

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 13
## Log

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 14
## Log

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 15
## Log
* [1] Completed

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": 15,
        "writtenAt": 16
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 16
## Log
* [1] Wrote to memory

## Registers
```json
[
]
```

## Stations
```json
[
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 1
## Log
* [1] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 2
## Log
* [2] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 3
## Log
* [3] Dispatched
* [2] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 4
## Log
* [3] Started

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 5
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 6
## Log
* [3] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": 6,
        "writtenAt": 7
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 7
## Log
* [3] Wrote to memory

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 8
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 9
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 10
## Log

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 11
## Log
* [2] Completed

## Registers
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": 11,
        "writtenAt": 12
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 12
## Log
* [1] Started
* [2] Wrote to memory

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 13
## Log

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 14
## Log

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 15
## Log
* [1] Completed

## Registers
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": 15,
        "writtenAt": 16
    }},
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CYCLE 16
## Log
* [1] Wrote to memory

## Registers
```json
[
]
```

## Stations
```json
[
]
```

## Memória (primeiras 8 posições)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 1
## Log
* [1] Dispatched
## Registradores
```json
[
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 2
## Log
* [2] Dispatched
## Registradores
```json
[
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 3
## Log
* [3] Dispatched
* [2] Started
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 4
## Log
* [3] Started
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 5
## Log
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 6
## Log
* [3] Completed
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
    {"id": 6, "busyByStation": 3, "busyByInst": 2, "v": 60},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": 6,
        "writtenAt": 7
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 7
## Log
* [3] Wrote to memory
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 8
## Log
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 9
## Log
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 10
## Log
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 11
## Log
* [2] Completed
## Registradores
```json
[
    {"id": 4, "busyByStation": 2, "busyByInst": 1, "v": 40},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": 11,
        "writtenAt": 12
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 12
## Log
* [1] Started
* [2] Wrote to memory
## Registradores
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 13
## Log
## Registradores
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 14
## Log
## Registradores
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 15
## Log
* [1] Completed
## Registradores
```json
[
    {"id": 1, "busyByStation": 0, "busyByInst": 0, "v": 10},
]
```
## Estacoes
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 12,
        "finishedAt": 15,
        "writtenAt": 16
    }},
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
# CICLO 16
## Log
* [1] Wrote to memory
## Registradores
```json
[
]
```
## Estacoes
```json
[
]
```

## Memoria (primeiras 8 posicoes)
```json
[ 0, 0, 0, 0, 0, 0, 0, 0 ]
```
