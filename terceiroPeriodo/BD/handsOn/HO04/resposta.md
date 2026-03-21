1. A = $\sigma$ gender = 'F' (actors)

    $\pi$ first_name, last_name (A)
2. A = $\sigma$ year > 1999 (movies)

    $\pi$ name(A)
3. A = $\rho$ id_mov &larr; id (movies)
    
    B = A $\bowtie$ id_mov = movie_id (movies_directors)

    C = B $\bowtie$ director_id = id (directors)

    $\pi$ name, first_name, last_name (C)
4. A = $\sigma$ rank > 6 (movies)

    B = $\rho$ id_mov &larr; id (A)

    C = B $\bowtie$ id_mov = movie_id (roles)

    D = C $\bowtie$ actor_id = id (actors)

    $\pi$ name, first_name, last_name, role(D)
5. A = directors $\bowtie$ id = director_id (movies_directors)

    $\gamma$ first_name, last_name; count(movie_id) &rarr; movie_count (A)
6.  $\gamma$ genre; count(movie_id) &rarr; mov_count (movies_genres)
7. A = (movies) $\bowtie$ id = movie_id (movies_genres)

    $\gamma$ genre; avg (rank) &rarr; rank_med, min (rank) &rarr; rank_min, max (rank) &rarr; rank_max (A)
