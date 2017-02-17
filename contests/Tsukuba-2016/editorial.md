A - Olhamos de a última aparição do número e para os valores não usados deixamos na ordem.

B - Problema de implementação.

C - Para cada ponto de saída calculamos a quantidade de produtos que vem de cima incluindo ele próprio, seja isso upper[i] e a quantidade de produtos que vem de baixo incluindo ele própro, seja isso lower[i]. Ordenamos as alavancas por x e depois por y e processamos cada alavanca e atualizamos com o respectivo valor de upper e lower. A resposta final para cada ponto de saída é lower[i]+upper[i]-1

D - 

G - Temos que colocar os medalhões na profundidade de seu valor, então o medalhão de valor i irá cobrir 1/2^i da árvore precisamos verificar se as somas dos medalhões é menor ou igual a 1. Sabemos que mudar um medalhão de valor i > 2*10^5 não vai mudar o valor final, exceto se a soma for igual a 1. 
