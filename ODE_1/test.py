import os
import matplotlib.pyplot as plt

print(os.getcwd())
os.chdir('tmp_data')
print(os.getcwd())

x = []
y = []
with open('data.data', 'r') as f:
    for line in f:
        if line.strip() == "":
            continue
        vals = line.strip().split()
        if len(vals) >= 2:
            x.append(float(vals[0]))
            y.append(float(vals[1]))

# グラフを描画
plt.plot(x, y, marker='o')
plt.xlabel('x')
plt.ylabel('y')
plt.title('data.dataのx-yグラフ')
plt.grid(True)
plt.show()