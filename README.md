# Comparação dos Métodos de Ordenação

## 1. **Bubble Sort**:
- **Complexidade**: O(n²) — ineficiente para listas grandes.
- **Vantagens**: Simples, útil para listas pequenas.
- **Desvantagens**: Desempenho ruim para listas grandes.

## 2. **Quick Sort**:
- **Complexidade**: O(n log n) no melhor caso; O(n²) no pior caso (com pivô ruim).
- **Vantagens**: Muito eficiente para listas grandes.
- **Desvantagens**: Pode ser lento com má escolha de pivôs.

---

# Escolha de Pivôs no Quick Sort

- **Pivô fixo (primeiro/último elemento)**: Simples, mas pode causar O(n²) em listas ordenadas.
- **Pivô aleatório**: Reduz o risco de O(n²), aumentando a eficiência.
- **Pivô mediano**: Melhor divisão, mais eficiente (como a "mediana de três", que escolhe entre o primeiro, último e meio).

---

**Resumo**: O objetivo é escolher um pivô que divida a lista de maneira equilibrada para garantir a complexidade O(n log n).
