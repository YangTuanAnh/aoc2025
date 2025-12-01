function solve()
    data = read("input.txt", String)
    ans = 0
    curr = 50

    for s in split(data)
        c = s[1]
        cnt = parse(Int, s[2:end])

        cnt %= 100

        prev = curr

        if c == 'L'
            curr -= cnt
        else
            curr += cnt
        end

        curr = mod(curr, 100)

        if curr == 0
            ans += 1
        end
    end

    println(ans)
end

solve()
