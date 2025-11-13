import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data/timings_gcd.csv")

g = df.groupby(["method", "max_value"])["time_ms"].median().reset_index()

plt.figure()
for method in ["naive", "euclid"]:
    sub = g[g["method"] == method].sort_values("max_value")
    if len(sub) == 0:
        continue
    plt.plot(sub["max_value"], sub["time_ms"], marker="o", label=method)

plt.xlabel("Максимальное значение чисел")
plt.ylabel("Время (мс)")
plt.title("Время работы алгоритмов НОД в зависимости от размера чисел")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("data/gcd_time.png")
plt.close()
