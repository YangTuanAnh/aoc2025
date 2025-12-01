function solve()
    data = read("input.txt", String)
    ans = 0
    curr = 50

    for s in split(data)
        c = s[1]
        cnt = parse(Int, s[2:end])

        ans += cnt ÷ 100
        cnt %= 100

        if cnt == 0
            continue
        end

        prev = curr

        if c == 'L'
            curr -= cnt
        else
            curr += cnt
        end

        if prev != 0 && (curr <= 0 || curr >= 100)
            ans += 1
        end

        curr = mod(curr, 100)
    end

    println(ans)
end

solve()
