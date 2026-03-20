1. A = $\sigma$ gender = 'F'(actors)

    $\pi$ first_name, last_name(A)
2. A = $\sigma$ year > 1999(movies)

    $\pi$ name(A)
3. A = $\rho$ id_mov&larr;id(movies)
    
    B = A $\fullouterjoin$