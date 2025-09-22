import pandas as pd
import matplotlib.pyplot as plt

# Load CSVs
single = pd.read_csv("single_times.csv", header=None, names=["Single(ms)"])
threaded = pd.read_csv("thread_times.csv", header=None, names=["Threaded(ms)"])

# Combine into one DataFrame
df = pd.concat([single, threaded], axis=1)
df["Run"] = range(1, len(df) + 1)

print("Timing Results Table:")
print(df)

# Save table to CSV (optional)
df.to_csv("fib_results.csv", index=False)

plt.plot(df["Run"], df["Single(ms)"], marker='o', label="Single Process")
plt.plot(df["Run"], df["Threaded(ms)"], marker="o", label="Multi-threaded")
plt.xlabel("Execution Number")
plt.ylabel("Execution Time (ms)")
plt.title("Fibonacci Execution Times Across Runs")
plt.yscale("log")
plt.legend()
plt.savefig("fib_avg_bar.png", dpi=300)
plt.show()

avg_times = df[["Single(ms)", "Threaded(ms)"]].mean()

avg_times.plot(kind="bar", color=["skyblue", "orange"])
plt.ylabel("Average Execution Time (ms)")
plt.title("Average Performance: Single vs Multi-threaded")
plt.xticks(rotation=45, ha="right")  # tilt labels 45° and align right
plt.tight_layout()  
plt.savefig("fib_avg_bar.png", dpi=300)
plt.show()



