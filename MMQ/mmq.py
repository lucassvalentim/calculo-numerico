import numpy as np
import matplotlib.pyplot as plt

# Dados de exemplo
x = np.array([1.0, 2.0, 3.0, 4.5, 6.0, 7.5, 9.0, 10.0, 11.0])
y = np.array([2.0, 25.0, 70, 80, 220, 250, 440, 500, 560])

# Ajuste de um polinômio de grau 2
coef = np.polyfit(x, y, 8)

# Criação do polinômio a partir dos coeficientes
p = np.poly1d(coef)

# Gerando os valores para o gráfico
x_plot = np.linspace(min(x), max(x), 100)
y_plot = p(x_plot)

# Vizualização
plt.scatter(x, y, color='red', label="Pontos")
plt.plot(x_plot, y_plot, label="Aproximação MMQ (grau 2)")
plt.legend()
plt.savefig('grafico.png')