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
5. A = actors $\bowtie$ id = actor_id (roles)

    B = $\rho$ first_name,last_name; count(actor_id) → roles_count (A)

    C = $\sigma$ roles_count <= 1 (B)

    $\pi$ first_name,last_name (C)
6. A = (movies) $\bowtie$ id = movie_id (movies_genres)

    B = $\rho$ id_mov ← movie_id (A)

    C = (B) $\bowtie$ id_mov = movie_id (roles)

    D = $\gamma$ role, genre, year; count(actor_id) &rarr; role_count(C)

    E = $\sigma$ role_count ≤ 2 (D)

    $\pi$ genre, year (E)