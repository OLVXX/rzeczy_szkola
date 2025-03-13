def czy_k_podobne(n, A, B, k):
    if A[:k] == B[n-k:] and A[k:] == B[:n-k]:
        return 'PRAWDA'
    else:
        return 'FAŁSZ'
