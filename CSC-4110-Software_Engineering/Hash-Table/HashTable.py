from ast import List

# Node we already are using
class Node:
    box: List
    man: int
    goal: int
    def __init__(self, box, man, goal):
        self.box = box
        self.man = man
        self.goal = goal
        
    def __eq__(self, other):
        return (self.box == other.box) and (self.man == other.man) and (self.goal == other.goal)

    def __ne__(self, other):
        return not (self == other)

    def __lt__(self, other):
        return (self.box < other.box) and (self.man < other.man) and (self.goal < other.goal)

    def __gt__(self, other):
        return (self.box > other.box) and (self.man > other.man) and (self.goal > other.goal)

    def __le__(self, other):
        return (self < other) or (self == other)

    def __ge__(self, other):
        return (self > other) or (self == other)

class HashTable:
    table: List
    
    # Constructor
    def __init__(self):
        self.table = []
    
    # Comparision operations
    def __eq__(self, other):
        return (self.table == other.table)

    def __ne__(self, other):
        return not (self.table == other.table)

    def __lt__(self, other):
        return (self.table < other.table)

    def __gt__(self, other):
        return (self.table > other.table)

    def __le__(self, other):
        return (self.table < other.table) or (self.table == other.table)

    def __ge__(self, other):
        return (self.table > other.table) or (self.table == other.table)
    
    def append_hash(self, node: Node):
        self.table.append({hash(chr(len(self.table))):node})
        
    def at(self, i: int):
        return self.table[i][hash(chr(i))]
    
    def toList(self):
        l = []
        for i in range(len(self.table)):
            l.append(self.table[i][hash(chr(i))])
        return l

# Creates Hash Table             
ht = HashTable()

# Applies value to hash table
ht.append_hash(Node([1,2,3],1,2))

# Prints first box attribute in hash table
print(ht.at(0).box)

# Converts all hash table entries into a list then prints first value's box attribute
print(ht.toList()[0].box)

