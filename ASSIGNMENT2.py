# IMPLEMENT HASH FUNCTION AND HANDLING COLLISION WITH CHAINING STORE STUDENT DETAIL

def HashNode():
        name=input("Enter Name of Student :- ")
        rollno=int(input("Enter roll Number :- "))
        return ({"name": name, "rollno": rollno})

def display(name,rollno):
    return " Student Name :- "+str(name)+"\n\t Roll Number :- "+str(rollno)

class HashTable:
    def __init__(self):
        self.size=10
        self.table=list(None for i in range(self.size))

    def insert(self):
        node=HashNode()
        position=node["rollno"]%self.size
        if self.table[position]==None:
            self.table[position] = [node]
        else:
            self.table[position].insert(position, node)

    def display(self):
        j=0
        for i in self.table:
            print(j," :- ",i)
            j=j+1

ht=HashTable()
while True:
    print(" 1. Insert Student Detail  ")
    print(" 2. Display Student Detail  ")
    print(" 3. Break ")
    ch=int(input("Enter Your Choice :- "))
    if ch==1:
        ht.insert()
    elif ch==2:
        ht.display()
    else:
        break