def knapsack(wt, val, W, n,matrix):
 
    # base conditions
    if n == 0 or W == 0:
        return 0
    if matrix[n][W] != -1:
        return matrix[n][W]
 
    # choice diagram code
    if wt[n-1] <= W:
        matrix[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1,matrix),
            knapsack(wt, val, W, n-1,matrix))
        return matrix[n][W]
    elif wt[n-1] > W:
        matrix[n][W] = knapsack(wt, val, W, n-1,matrix)
        return matrix[n][W]

def main():
    
    casos_de_teste = int(input())
    enfeites = []
    pesos = []
    
    for i in range(1,casos_de_teste+1):
        qnt_pacotes = int(input())
        capacidade_galho = int(input())

        for j in range(qnt_pacotes):
            qnt_enfeites,peso_pacote = map(int,(input().split()))
            enfeites.append(qnt_enfeites)
            pesos.append(peso_pacote)
        
        matrix = [[-1 for i in range(capacidade_galho + 1)] for j in range(qnt_pacotes + 1)]

        num_enfeites_galho = knapsack(pesos,enfeites,capacidade_galho,qnt_pacotes,matrix)

        print(f"Galho {i}:")
        print(f"Numero total de enfeites: {num_enfeites_galho}")
        #if(i != casos_de_teste):
        print()
        enfeites = []
        pesos = []

main()