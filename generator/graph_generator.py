import random
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt


class GraphGenerator:

    def __init__(self, max_nodes, max_edges):
        self.max_nodes = max_nodes
        self.max_edges = max_edges

    def generate_graph(self, seed=random.randint(0, 1000), verbose=True):
        n_nodes = self.max_nodes
        m_edges = self.max_edges
        p = 2 * m_edges / (n_nodes * (n_nodes - 1))
        if verbose:
            print('Maximum Edges', n_nodes * (n_nodes - 1) / 2)
            print('Probability to make an edge', p)
        G = nx.generators.fast_gnp_random_graph(n_nodes, p, seed=seed)
        if verbose:
            print('Edges', len(G.edges))
            print('Connectivity', nx.is_connected(G))
        self.G = G
        return G

    def generate_weighted_graph(self, w_range=(0, 100), seed=random.randint(0, 1000),
                                verbose=True, connectivity=True):
        n_nodes = self.max_nodes
        m_edges = self.max_edges
        p = 2 * m_edges / (n_nodes * (n_nodes - 1))
        if verbose:
            print('Maximum Edges', n_nodes * (n_nodes - 1) / 2)
            print('Probability to make an edge', p)
        G = nx.generators.fast_gnp_random_graph(n_nodes, p, seed=seed)
        if (connectivity):
            while (not nx.is_connected(G)):
                G = nx.generators.fast_gnp_random_graph(n_nodes, p, seed=random.randint(0, 1000))
        for (u, v, w) in G.edges(data=True):
            w['weight'] = random.randint(w_range[0], w_range[1])
        if verbose:
            print('Edges', len(G.edges))
            print('Connectivity', nx.is_connected(G))
        self.G = G
        return G

    @staticmethod
    def get_distance(A, B, decimals=5):
        dist = np.linalg.norm(np.array(list(A)) - np.array(list(B)))
        return round(dist, decimals)

    def generate_pseudo_real_graph(self, w_range=(1, 100),
                                   seed=random.randint(0, 1000),
                                   verbose=True, connectivity=True,
                                   xOy_range=(-1000, 1000)):
        n_nodes = self.max_nodes
        m_edges = self.max_edges
        p = 2 * m_edges / (n_nodes * (n_nodes - 1))
        if verbose:
            print('Maximum Edges', n_nodes * (n_nodes - 1) / 2)
            print('Probability to make an edge', p)
        G = nx.generators.fast_gnp_random_graph(n_nodes, p, seed=seed)
        if (connectivity):
            while (not nx.is_connected(G)):
                G = nx.generators.fast_gnp_random_graph(n_nodes, p, seed=seed)

        for v in G.nodes:
            x, y = random.randint(*xOy_range), random.randint(*xOy_range)
            G.nodes[v]['coordinate'] = (x, y)

        for (u, v, w) in G.edges(data=True):
            w['weight'] = self.get_distance(G.nodes[u]['coordinate'],
                                            G.nodes[v]['coordinate'])
        if verbose:
            print('Edges', len(G.edges))
            print('Connectivity', nx.is_connected(G))
        self.G = G
        return G

    def draw_graph(self, G=None, figsize=(8, 3)):
        if not G:
            try:
                G = self.G
            except:
                print('ERROR: Graph G does not exist. \
                       \nSpeify arg G or call generate_graph methods')
                return
        plt.figure(figsize=(figsize[0], figsize[1]))
        pos = nx.spring_layout(G)
        nx.draw(G, pos)
        nx.draw_networkx_labels(G, pos, font_color='white',
                                font_weight='bold')
        labels = nx.get_edge_attributes(G, 'weight')
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
        plt.draw()
        plt.show()
        return

    @staticmethod
    def save_to_file(graph, filename):
        lines = []
        for node in graph.nodes:
            line = []
            for neigh in graph.neighbors(node):
                line.append(neigh)
                line.append(graph[node][neigh]['weight'])
            line = ' '.join(map(str, line)) + '\n'
            lines.append(line)
        with open(filename, 'w') as file:
            file.writelines(lines)
            file.close()

    @staticmethod
    def save_sp_dist(dist, filename):
        _dist = [dist[i] for i in range(len(dist))]
        with open(filename, 'w') as file:
            file.writelines(' '.join(map(str, _dist)))
            file.close()


if __name__ == '__main__':
    N = 15
    gen = GraphGenerator(max_nodes=N, max_edges=10*N)
    G = gen.generate_weighted_graph(w_range=(0, 100))
    pred, dist = nx.dijkstra_predecessor_and_distance(G, 0, weight='weight')
    for i in range(N):
        print(f"{i}\t{dist[i]}")
    i = 3
    gen.save_to_file(G, f'../benchmarks/unit/unit_test{i}.txt')
    gen.save_sp_dist(dist, f'../benchmarks/unit/unit_test{i}_answer.txt')
