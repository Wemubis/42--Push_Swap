# Push_swap

## Introduction

Ce projet a été réalisé dans le cadre du cursus à l'école 42. L'objectif principal est de créer un algorithme efficace pour trier une pile d'entiers en utilisant un ensemble limité d'instructions, tout en minimisant le nombre total d'instructions.

<br>

## Description

Push_swap implémente un algorithme de tri qui prend une pile d'entiers en entrée et utilise deux piles (A et B) ainsi que diverses opérations pour trier les entiers dans l'ordre croissant. Les opérations autorisées sont, entre autres, `sa` (swap a), `sb` (swap b), `ss` (swap a et b), `pa` (push a), `pb` (push b), `ra` (rotate a), "rb" (rotate b), `rr` (rotate a et b), `rra` (reverse rotate a), et `rrb` (reverse rotate b).

<br>

## Fonctionnalités

- Tri efficace de la pile d'entiers.
- Minimisation du nombre total d'instructions.
- Gestion d'un petit nombre d'entiers (environ 5 à 500 éléments).

<br>

## Implémentation

L'algorithme utilise une combinaison de tri par insertion et d'autres techniques pour minimiser le nombre d'instructions nécessaires. L'approche comprend plusieurs étapes, notamment la division de la pile initiale en segments et le tri de ces segments, suivi de la fusion des segments triés pour obtenir la pile finale triée.

<br>

## Utilisation

1. **Clonage du dépôt :**
```bash
  git clone https://github.com/Wemubis/push_swap.git
```

3. **Compilation :**
```bash
  make
```

5. **Exécution :**
```bash
  ./push_swap 3 2 1
```

7. **Vérification avec le checker :**
```bash
  ./push_swap 3 2 1 | ./checker 3 2 1
```

<br>

## Ressources

- [Sujet du projet push_swap](https://github.com/42Paris/push_swap/blob/master/en.subject.pdf)
- [Algorithme de tri par insertion](https://en.wikipedia.org/wiki/Insertion_sort)
- [Wiki push_swap : règles et opérations](https://github.com/toniandreas/push_swap/wiki/Rules-and-operations)
