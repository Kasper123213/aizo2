import matplotlib.pyplot as plt
from numpy import mean, linspace, std
import numpy as np
from scipy.interpolate import make_interp_spline
from scipy.optimize import curve_fit
from math import log

def readFile(filename):
    try:
        with open(filename, 'r') as file:
            times = file.read()
            return times

    except FileNotFoundError:
        print(f"Plik {filename} nie został znaleziony.")
    except Exception as e:
        print(f"Wystąpił błąd podczas wczytywania pliku {filename}: {e}")


def makeList(content):
    avg = []
    content = content.split("\n")[:-1]
    content = [l.split(";") for l in content]

    for i in range(len(content)):
        content[i] = [int(l)/1000 for l in content[i][:-1]]
        avg.append(mean(content[i]))

    return content, avg
#
#
# def savePlot(plot, filename):
#     plot.savefig(filename)
#
def makePlot(x, y):

    X_Y_Spline = make_interp_spline(x, y)
    X_ = linspace(300, 900, 100)
    Y_ = X_Y_Spline(X_)


    return X_, Y_

kruskalList = readFile("wyniki/KruskalAlgorithmList.csv")
kruskalList, klAVG = makeList(kruskalList)

kruskalMatrix = readFile("wyniki/KruskalAlgorithmMatrix.csv")
kruskalMatrix, kmAVG = makeList(kruskalMatrix)


PrimAlgorithmList = readFile("wyniki/PrimAlgorithmList.csv")
PrimAlgorithmList, plAVG = makeList(PrimAlgorithmList)

PrimAlgorithmMatrix = readFile("wyniki/PrimAlgorithmMatrix.csv")
PrimAlgorithmMatrix, pmAVG = makeList(PrimAlgorithmMatrix)



dataSizes = [i for i in range(100, 701, 100)] #7 rozmiarów

# for i in dmAVG:
#     print(i)


#

y = kmAVG[14:21]
x, y = makePlot(dataSizes, y)
plt.plot(x, y, label="Kruskal, reprezentacja macierzowa")

y = klAVG[14:21]
x, y = makePlot(dataSizes, y)
plt.plot(x, y, label="Kruskal, reprezentacja listowa")

y = pmAVG[14:21]
x, y = makePlot(dataSizes, y)
plt.plot(x, y, label="Prim, reprezentacja macierzowa")

y = plAVG[14:21]
x, y = makePlot(dataSizes, y)
plt.plot(x, y, label="Prim, reprezentacja listowa")





plt.legend()

plt.ylabel('Czas [s]')
plt.xlabel('Rozmiar grafu')

plt.grid(True)


# plt.show()
filename = "mst99.png"
plt.savefig(filename)

plt.close()

# #porownanie czasow dla kazdego algorytmu osobno(kazdego pliku
# y = dlAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 25")
#
# y = dlAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 50")
#
# y = dlAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 99")
#
# plt.legend()
#
# plt.ylabel('Czas [ms]')
# plt.xlabel('Rozmiar grafu')
#
# plt.grid(True)


# plt.show()
filename = "dijkstraList.png"
plt.savefig(filename)
plt.close()


# #porownanie czasow dla kazdego algorytmu osobno(kazdego pliku
# y = blAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 25")
#
# y = blAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 50")
#
# y = blAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 99")
#
# plt.legend()
#
# plt.ylabel('Czas [ms]')
# plt.xlabel('Rozmiar grafu')
#
# plt.grid(True)
#
#
# # plt.show()
# filename = "bellmanFordLista.png"
# plt.savefig(filename)
# plt.close()
#
# #porownanie czasow dla kazdego algorytmu osobno(kazdego pliku
# y = bmAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 25")
#
# y = bmAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 50")
#
# y = bmAVG[14:21]
# x, y = makePlot(dataSizes, y)
# plt.plot(x, y, label="Gęstość 99")
#
# plt.legend()
#
# plt.ylabel('Czas [ms]')
# plt.xlabel('Rozmiar grafu')
#
# plt.grid(True)
#
#
# # plt.show()
# filename = "BellmanFordMatrix.png"
# plt.savefig(filename)
# plt.close()