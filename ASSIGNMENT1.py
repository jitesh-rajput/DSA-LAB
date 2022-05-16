# Implement Hash Table to store client's mobile number

class HashNode:
    def __init__(self):
        self.name=""
        self.mnum=0
    def __str__(self):
        return "Name :- "+str(self.name)+"\n\tMobile No. :- "+str(self.mnum)

class HashTable:
    def __init__(self):
        self.size=int(input("Enter the size of HashTable :- "))
        self.ls =list(None for i in range(self.size))
        self.element=0

    def isFull(self):
        if self.size==self.element:
            return True
        else:
            return False
    def hash(self,mnum):
        return mnum%self.size

    def insert(self):
        if self.isFull():
            print("Hash Table Overflow ..!")
            return
        h=HashNode()
        h.name=input("Enter Name of Client :- ")
        h.mnum=int(input("Enter Number of Client :- "))
        position = self.hash(h.mnum)
        print(position)
        if self.ls[position]==None:
            self.ls[position]=h
            self.element+=1
            print("Data stored at index ",position)
        else:
            print("Collision Occured at position ",position)
            if position>=self.size:
                position=0
            while(self.ls[position]!=None):
                if position >= self.size:
                    position = 0
                position=position+1
            self.ls[position] = h
            self.element+=1
            print("Data stored at index " , position)

    def display(self):
        j=1
        for i in self.ls:
            print(j," :- ",end="")
            print(i)
            j=j+1
ht=HashTable()
while True:
    print(" 1. Insert ")
    print(" 2. Display ")
    print(" 3. Break ")
    ch=int(input("Enter Your Choice :- "))
    if ch==1:
        ht.insert()
    elif ch==2:
        ht.display()
    else:
        break