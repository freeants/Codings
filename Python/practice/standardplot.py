import matplotlib.pyplot as plt
import numpy as np

# Create a list of evenly-spaced numbers over the range
x = np.linspace(0, 12,150)
# Plot the sin&cos of each x point
plt.plot(x, np.sin(x), label="sin")
plt.plot(x, np.cos(x), label="cos", linestyle="--")
# Display the plot
plt.title("sin & cos")
plt.legend()
plt.show()
