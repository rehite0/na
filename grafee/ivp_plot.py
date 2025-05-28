#!/usr/bin/env python

import matplotlib.pyplot as plt
import subprocess as sp

def main():
    l=("eular","huen","modec","rk4")
    for i in l:
        dir=f"../{i}/"
        sp.run("pushd "+dir+"&& make && popd",shell=True,stdout=sp.DEVNULL)
        print(dir+'a.out |awk \'NR!=1{print $1 "  " $3}\' >'+i+".gaf")
        sp.run(dir+'a.out |awk \'NR!=1{print $1 "  " $3}\' >'+i+".gaf"
               ,shell=True,stdout=sp.DEVNULL)
        plot(i+".gaf",label=i)

    plt.xlabel("x")
    plt.ylabel("approx")
    plt.legend()
    plt.show()

def plot(file,label=""):
    x=list()
    y=list()
    with open(file) as f:
        lines=f.readlines()
    for l in lines:
        l=tuple(map(float,l.split()))
        x.append(l[0])
        y.append(l[1])
    plt.plot(x,y,label=label)

if __name__=="__main__":
    main()
