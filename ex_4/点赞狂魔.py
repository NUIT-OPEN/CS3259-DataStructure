n = int(input())
users = []
for i in range(n):
    line = input()
    words = line.split(' ')
    username = words[0]
    words = words[2:]
    words_count = {word:words.count(word) for word in words}
    word_num = len(words_count)
    users.append(
        dict(
            username=username,
            count=word_num,
            avg_count=sum(words_count.values()) / word_num,
        )
    )

users = sorted(users, key=lambda x:(x['count'], -x['avg_count']), reverse=True)
for i in range(3):
    print(users[i]['username'] if i < len(users) else '-', end=' ' if i < 2 else '')
