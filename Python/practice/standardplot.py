import matplotlib.pyplot as plt
import numpy as np

# Create a list of evenly-spaced numbers over the range
x = np.linspace(-2*np.pi, 2*np.pi, 512)
# Plot the sin&cos of each x point
plt.xticks([-2*np.pi, -np.pi, 0, np.pi, 2*np.pi],
           ['-2π', '-π', '0', 'π', '2π'])
plt.yticks([-1,  0, 1])
plt.plot(x, np.sin(x), label="sin")
plt.plot(x, np.cos(x), label="cos", linestyle="--")
# Display the plot
plt.title("sin & cos")
plt.legend()
plt.show()
