
import sys

# A2B2A1B2A2B1A2B2A1B2A1A1B1A1A2

for line in sys.stdin:
    line = line.strip()
    scores = {"A": 0, "B": 0}
    gap = 1
    for i in range(0, len(line), 2):
        tag = line[i]
        n = int(line[i + 1])
        scores[tag] += n
        if scores["A"] == scores["B"] == 10:
            gap = 2

        if gap == 1:
            if scores["A"] == 11:
                print("A")
                break
            if scores["B"] == 11:
                print("B")
                break
        else:
                
            if scores["A"] - scores["B"] >= gap:
                print("A")
                break
            elif scores["B"] - scores["A"] >= gap:
                print("B")
                break
        
        
        
