A - Olhamos de a última aparição do número e para os valores não usados deixamos na ordem.

B - Problema de implementação.

C - Para cada ponto de saída calculamos a quantidade de produtos que vem de cima incluindo ele próprio, seja isso upper[i] e a quantidade de produtos que vem de baixo incluindo ele própro, seja isso lower[i]. Ordenamos as alavancas por x e depois por y e processamos cada alavanca e atualizamos com o respectivo valor de upper e lower. A resposta final para cada ponto de saída é lower[i]+upper[i]-1

D - Podemos guardar a quantidade de cada tipo de letra num intervalo (i,j) para as duas strings, com soma acumulada, dando O(26*N^2).
Procurar num map, se aparece uma das substrings na substring da outra, mas isso daria memory limit exceed, um jeito de contornar isso é fazer para cada tamanho de letra.

E - Problema de implementação. 

G - Temos que colocar os medalhões na profundidade de seu valor, então o medalhão de valor i irá cobrir 1/2^i da árvore. Então precisamos verificar se as somas dos medalhões é menor ou igual a 1. Guardamos um vetor de 0,1 que diz que na i-esima posição a quantidade da árvore de 1/2^i que foi utilizada e sempre que virá 2 em uma posição somamos 1 na posição i-1-ésima posição e zeramos a i-ésima posição, se a posição 0 tiver valor 1, a árvore está cheia.  Sabemos que mudar um medalhão de valor i > 2*10^5 não vai mudar o valor final, pois ele irá percorrer no máximo N operações, exceto se a soma for igual a 1 + eps. Podemos simular essas operações com uma estrutura de dados como BIT, dando uma complexidade de O(n*logn)
