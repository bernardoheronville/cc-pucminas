1. A = $\pi$ first_name, last_name (actors)

    B = $\pi$ first_name, last_name (directors)

    A $\cap$ B
2. A = $\pi$ first_name, last_name (actors)

    B = $\pi$ first_name, last_name (directors)

    A - B 
3. A = $\pi$ first_name, last_name (actors)

    B = $\pi$ first_name, last_name (directors)

    A $\cup$ B
4. A = $\pi$ id (movies)

    B = $\pi$ movie_id (movies_directors)

    C = A - B

    D = (C) $\bowtie$ id = id (movies)

    $\pi$ name (D)
5. A = $\gamma$ actor_id; count(actor_id) &rarr; count_id (roles)

    B = $\sigma$ count_id >= 2 (A)

    C = $\pi$ id (actors) - $\pi$ actor_id (B)

    D = $\rho$ ida &larr; id (C)

    E = (D) $\bowtie$ ida = id (actors)

    $\pi$ first_name, last_name (E)
6. A = (movies) $\bowtie$ id = movie_id (movies_genres)

    B = $\rho$ id_mov ← movie_id (A)

    C = (B) $\bowtie$ id_mov = movie_id (roles)

    D = $\gamma$ role, genre, year; count(actor_id) &rarr; role_count(C)

    E = $\sigma$ role_count ≤ 2 (D)

    $\pi$ genre, year (E)