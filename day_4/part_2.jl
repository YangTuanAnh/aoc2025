dx = [-1, 0, 1, 1, 1, 0, -1, -1]
dy = [-1, -1, -1, 0, 1, 1, 1, 0]

function solve()
    g = readlines("input.txt")
    n = length(g)
    m = length(g[1])

    grid = [collect(row) for row in g]

    cnt_adj = [zeros(Int, m) for _ in 1:n]   
    q = Base.RefValue{Vector{Tuple{Int,Int}}}([])
    q[] = Tuple{Int,Int}[]

    for i in 1:n, j in 1:m
        if grid[i][j] != '@'
            continue
        end

        cnt = 0
        for k in 1:8
            ni = i + dx[k]
            nj = j + dy[k]
            if 1 <= ni <= n && 1 <= nj <= m
                cnt += (grid[ni][nj] == '@')
            end
        end

        cnt_adj[i][j] = cnt
        if cnt < 4
            push!(q[], (i, j))
        end
    end

    ans = 0

    while !isempty(q[])
        i, j = popfirst!(q[])
        if grid[i][j] != '@'
            continue
        end

        grid[i][j] = '.'
        ans += 1

        for k in 1:8
            ni = i + dx[k]
            nj = j + dy[k]
            if 1 <= ni <= n && 1 <= nj <= m && grid[ni][nj] == '@'
                cnt_adj[ni][nj] -= 1
                if cnt_adj[ni][nj] == 3
                    push!(q[], (ni, nj))
                end
            end
        end
    end

    println(ans)
end

solve()
