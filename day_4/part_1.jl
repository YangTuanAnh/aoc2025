dx = [-1, 0, 1, 1, 1, 0, -1, -1]
dy = [-1, -1, -1, 0, 1, 1, 1, 0]

function solve()
    g = readlines("input.txt")
    n = length(g)
    m = length(g[1])

    ans = 0

    for i in 1:n
        for j in 1:m
            g[i][j] == '@' || continue

            cnt = 0
            for k in 1:8
                ni = i + dx[k]
                nj = j + dy[k]
                if 1 <= ni <= n && 1 <= nj <= m
                    cnt += (g[ni][nj] == '@')
                end
            end

            ans += (cnt < 4)
        end
    end

    println(ans)
end

solve()
