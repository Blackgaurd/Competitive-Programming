# CCC '22 J2 - Fergusonball Ratings

n = int(input())
star_players = 0
for i in range(n):
    points = int(input())
    fouls = int(input())
    rating = 5 * points - 3 * fouls

    star_players += rating > 40

if star_players == n:
    print(f"{star_players}+")
else:
    print(star_players)
