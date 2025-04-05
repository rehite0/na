import matplotlib.pyplot as plt

def main():
    for _ in range(int(input("enter no of graph:"))):
        l=input("lable for the graph:")
        plot(l)
    plt.xlabel("x")
    plt.ylabel("approx")
    plt.legend()
    plt.show()

def plot(l):
    x=list()
    y=list()
    while(1):
        i=input()
        if(i=='q'):
           break
        i=i.split()
        i=tuple(map(float,i))
        x.append(i[0])
        y.append(i[1])
    plt.plot(x,y,label=l)

if __name__=="__main__":
    main()
