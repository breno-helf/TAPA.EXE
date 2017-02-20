A - Olhamos de a última aparição do número e para os valores não usados deixamos na ordem.

B - Problema de implementação.

C - Para cada ponto de saída calculamos a quantidade de produtos que vem de cima incluindo ele próprio, seja isso upper[i] e a quantidade de produtos que vem de baixo incluindo ele própro, seja isso lower[i]. Ordenamos as alavancas por x e depois por y e processamos cada alavanca e atualizamos com o respectivo valor de upper e lower. A resposta final para cada ponto de saída é lower[i]+upper[i]-1

D - Podemos guardar a quantidade de cada tipo de letra num intervalo (i,j) para as duas strings, com soma acumulada, dando O(26*N^2).
Procurar num map, se aparece uma das substrings na substring da outra, mas isso daria memory limit exceed, um jeito de contornar isso é fazer para cada tamanho de letra.

E - Problema de implementação. 

F - Inicialmente parece um problema de geometria, mas estudando um pouco o problema percebemos que o problema pode ser reduzido ao um problema de Teoria dos Números. Suponha que temos apenas três pontos,(0,0),(xdd,ydd), (c,d), então a área dele vale abs(xdd*d-ydd*c)/2 = g/2, entao enquanto g/2 <= 25000, podemos usar o algoritmo de euclides extendido para resolver. Por outro quando g/2>25000, podemos escolher (0,0),(xdd-1,ydd),(xdd,ydd-1),(xdd/g,ydd/g), que tem área igual a (xdd/g+ydd/g)/2 <= 25000


G - Temos que colocar os medalhões na profundidade de seu valor, então o medalhão de valor i irá cobrir 1/2^i da árvore. Então precisamos verificar se as somas dos medalhões é menor ou igual a 1. Guardamos um vetor de 0,1 que diz que na i-esima posição a quantidade da árvore de 1/2^i que foi utilizada e sempre que virá 2 em uma posição somamos 1 na posição i-1-ésima posição e zeramos a i-ésima posição, se a posição 0 tiver valor 1, a árvore está cheia.  Sabemos que mudar um medalhão de valor i > 2*10^5 não vai mudar o valor final, pois ele irá percorrer no máximo N operações, exceto se a soma for igual a 1 + eps. Podemos simular essas operações com uma estrutura de dados como BIT, dando uma complexidade de O(n*logn)


K - Usando as propriedades dos números surreais, o problema virá o maior subset que contem mais elementos que a soma dá zero, usando meet-in-the-middle é bem fácilmente resolvido em O(n*2^(n/2))
