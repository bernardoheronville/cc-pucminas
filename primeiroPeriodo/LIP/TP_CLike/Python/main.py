# Declara e lê uma variável inteira N
N = int(input())

# Calcula a distância como (N - 3) módulo 8
distancia = (N - 3) % 8

if distancia == 3: # Se a distância for 3
    print("1") # Imprime 1
elif distancia == 4: # Se a distância for 4
    print("2") # Imprime 2
elif distancia == 5: # Se a distância for 5
    print("3") # Imprime 3
else: #Para qualquer outro valor de distância
    print("ERRO") # Imprime ERRO 