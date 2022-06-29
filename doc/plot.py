#!/usr/bin/python3

import matplotlib.pyplot as plt


def load_data(filename):
    filename = "../data/" + filename
    with open(filename, 'r') as f:
        file = f.read().split('\n')[:-1]
    return [ [ int(num) for num in row.split(" ") ] for row in file ]


def parse_data(data):
    size = []
    op_el = []
    op_base = []

    for s, ob, oe in data:
        size.append(s)
        op_el.append(oe)
        op_base.append(ob)
    return size, op_el, op_base


def drawplot(algorithm_name, size, random, sort, isort, domi):
    fig, ax = plt.subplots(figsize=(8, 7))
    ax.set_title(algorithm_name)
    ax.set_xlabel('Rozmiar tablicy')
    ax.set_ylabel("Operacje elementarne")
    ax.grid(True);

    # fill four 
    ax.plot(size, random, label='dane losowe')
    ax.legend()
    ax.plot(size, sort, label='dane posortowane')
    ax.legend()
    ax.plot(size, isort, label='dane posortowane odwrotnie')
    ax.legend()
    ax.plot(size, domi, label='elementy dominujące')
    ax.legend()

    plt.savefig(algorithm_name+'.png');


def draw_sort_plot(sort_name):
    sort = load_data(sort_name + "-sort.txt")
    isort = load_data(sort_name + "-inversed_sort.txt")
    random = load_data(sort_name + "-random.txt")

    size, sort, op_base = parse_data(sort)
    size, isort, op_base2 = parse_data(isort)
    size, random, op_base3 = parse_data(random)

    # should be same because of nature of dominant operations
    # for some reason I wasn't able to find anything about
    # "dominant operations" on english web, that's why name base
    # which is apparently something else
    if op_base != op_base2 or op_base2 != op_base3:
        print("op_base differ!")

    drawplot(sort_name.replace('_', ' '), size, random, sort, isort, op_base)

draw_sort_plot("insert_sort")
draw_sort_plot("merge_sort")
draw_sort_plot("selection_sort")
