document.addEventListener('DOMContentLoaded', () => {
    const simulateBtn = document.getElementById('simulateBtn');
    const frequencyInput = document.getElementById('frequency');
    const averageBetValueInput = document.getElementById('averageBetValue');
    const simulationTimeInput = document.getElementById('simulationTime');
    const resultsSection = document.getElementById('resultsSection');
    const timeResultSpan = document.getElementById('timeResult');
    const moneySavedResultSpan = document.getElementById('moneySavedResult');
    const moneyInvestedResultSpan = document.getElementById('moneyInvestedResult');
    const conquestsGrid = document.getElementById('conquestsGrid');
    const ctx = document.getElementById('simulationGrowthChart').getContext('2d');

    let simulationChart;

    simulateBtn.addEventListener('click', () => {
        const frequency = frequencyInput.value;
        const averageBetValue = parseFloat(averageBetValueInput.value);
        const simulationTimeYears = parseInt(simulationTimeInput.value);
        const simulationTimeMonths = simulationTimeYears * 12;

        if (isNaN(averageBetValue) || averageBetValue <= 0) {
            alert('Por favor, insira um valor médio de aposta válido (maior que zero).');
            return;
        }

        let betsPerMonth;
        switch (frequency) {
            case 'daily':
                betsPerMonth = averageBetValue * 30;
                break;
            case 'weekly':
                betsPerMonth = averageBetValue * (365 / 7 / 12);
                break;
            case 'biweekly':
                betsPerMonth = averageBetValue * (365 / 14 / 12);
                break;
                case 'monthly':
                betsPerMonth = averageBetValue * 1;
                break;
        }

        let totalMoneySaved = 0;
        let totalMoneyInvested = 0;
        const monthlyInvestmentRate = 0.005; // 0.5% ao mês (6% ao ano)
        
        // Dados para o gráfico de linhas (mensal)
        const labels = [];
        const moneySavedData = [];
        const moneyInvestedData = [];

        labels.push('Mês 0');
        moneySavedData.push(0);
        moneyInvestedData.push(0);

        for (let i = 1; i <= simulationTimeMonths; i++) {
            totalMoneySaved += betsPerMonth;
            totalMoneyInvested = (totalMoneyInvested + betsPerMonth) * (1 + monthlyInvestmentRate);
            
            labels.push(`Mês ${i}`);
            moneySavedData.push(totalMoneySaved.toFixed(2));
            moneyInvestedData.push(totalMoneyInvested.toFixed(2));
        }


        // Exibir resultados finais
        timeResultSpan.textContent = `${simulationTimeYears} Ano${simulationTimeYears > 1 ? 's' : ''}`;
        moneySavedResultSpan.textContent = `R$ ${totalMoneySaved.toLocaleString('pt-BR', { minimumFractionDigits: 2, maximumFractionDigits: 2 })}`;
        moneyInvestedResultSpan.textContent = `R$ ${totalMoneyInvested.toLocaleString('pt-BR', { minimumFractionDigits: 2, maximumFractionDigits: 2 })}`;
        
        resultsSection.style.display = 'block';
        resultsSection.scrollIntoView({ behavior: 'smooth', block: 'start' });

        // Atualizar/Criar o gráfico de linhas
        if (simulationChart) {
            simulationChart.destroy();
        }

        simulationChart = new Chart(ctx, {
            type: 'line', 
            data: {
                labels: labels, // Usar labels mensais para linha
                datasets: [{
                    label: 'Economizado (Sem Aposta)',
                    data: moneySavedData,
                    borderColor: '#64B5F6', 
                    backgroundColor: 'rgba(100, 181, 246, 0.3)', 
                    fill: true,
                    tension: 0.4, 
                    pointRadius: 4, 
                    pointBackgroundColor: '#64B5F6',
                    pointBorderColor: '#FFF',
                    pointHoverRadius: 6,
                    pointHoverBackgroundColor: '#64B5F6'
                },
                {
                    label: 'Economizado + Juros (0.5% a.m.)',
                    data: moneyInvestedData,
                    borderColor: '#1976D2', 
                    backgroundColor: 'rgba(25, 118, 210, 0.3)', 
                    fill: true,
                    tension: 0.4,
                    pointRadius: 4,
                    pointBackgroundColor: '#1976D2',
                    pointBorderColor: '#FFF',
                    pointHoverRadius: 6,
                    pointHoverBackgroundColor: '#1976D2'
                }]
            },
            options: {
                responsive: true,
                maintainAspectRatio: false,
                plugins: {
                    title: {
                        display: true,
                        text: 'Crescimento do Seu Dinheiro ao Longo do Tempo',
                        font: {
                            size: 18,
                            weight: 'bold'
                        },
                        color: '#333',
                        padding: 20
                    },
                    tooltip: {
                        mode: 'index',
                        intersect: false,
                        backgroundColor: 'rgba(25, 118, 210, 0.9)',
                        titleFont: { size: 14, weight: 'bold' },
                        bodyFont: { size: 13 },
                        padding: 12,
                        cornerRadius: 6,
                        displayColors: true
                    },
                    legend: {
                        display: true,
                        position: 'bottom',
                        labels: {
                            font: {
                                size: 13
                            },
                            color: '#555',
                            usePointStyle: true,
                            padding: 20
                        }
                    }
                },
                scales: {
                    x: {
                        title: {
                            display: true,
                            text: 'Tempo (Meses)', 
                            font: { size: 15, weight: 'bold' },
                            color: '#555'
                        },
                        grid: {
                            display: false 
                        },
                        ticks: {
                            color: '#666',
                            font: { size: 12 },
                            
                            autoSkip: true,
                            maxTicksLimit: 12 
                        }
                    },
                    y: {
                        beginAtZero: true,
                        title: {
                            display: true,
                            text: 'Valor Acumulado (R$)',
                            font: { size: 15, weight: 'bold' },
                            color: '#555'
                        },
                        ticks: {
                            callback: function(value, index, values) {
                                return 'R$ ' + value.toLocaleString('pt-BR', { minimumFractionDigits: 0, maximumFractionDigits: 0 });
                            },
                            color: '#666',
                            font: { size: 12 }
                        },
                        grid: {
                            color: 'rgba(0,0,0,0.08)', 
                            borderColor: 'rgba(0,0,0,0.1)'
                        }
                    }
                },
                animation: {
                    duration: 1200, 
                    easing: 'easeInOutQuart' 
                },
                hover: {
                    mode: 'nearest', 
                    intersect: true
                }
            }
        });

        // Gerar exemplos de conquistas
        generateConquests(totalMoneyInvested);
    });

    function generateConquests(totalValue) {
        conquestsGrid.innerHTML = '';

        const allConquests = [
            { threshold: 500, description: 'Fazer aquele curso online que vai alavancar sua carreira.', icon: 'fa-solid fa-graduation-cap' },
            { threshold: 1000, description: 'Investir na sua saúde: um check-up completo ou tratamento odontológico.', icon: 'fa-solid fa-heart-pulse' },
            { threshold: 1500, description: 'Comprar um novo smartphone ou um tablet para estudos/lazer.', icon: 'fa-solid fa-mobile-screen-button' },
            { threshold: 2500, description: 'Ter uma reserva de emergência para imprevistos.', icon: 'fa-solid fa-hand-holding-dollar' },
            { threshold: 3000, description: 'Fazer uma viagem de fim de semana para um lugar relaxante.', icon: 'fa-solid fa-plane' },
            { threshold: 5000, description: 'Quitar uma dívida pequena e respirar aliviado(a).', icon: 'fa-solid fa-money-bill-transfer' },
            { threshold: 7500, description: 'Reformar um cômodo da sua casa ou comprar novos eletrodomésticos.', icon: 'fa-solid fa-house-chimney' },
            { threshold: 10000, description: 'Dar a entrada em uma moto ou um carro popular.', icon: 'fa-solid fa-car' },
            { threshold: 15000, description: 'Investir em uma nova habilidade ou iniciar um pequeno negócio.', icon: 'fa-solid fa-lightbulb' },
            { threshold: 20000, description: 'Realizar aquela viagem internacional dos seus sonhos.', icon: 'fa-solid fa-earth-americas' },
            { threshold: 30000, description: 'Pagar a faculdade ou uma pós-graduação de alto nível.', icon: 'fa-solid fa-university' },
            { threshold: 50000, description: 'Dar a entrada na sua casa própria, o maior dos investimentos.', icon: 'fa-solid fa-house' },
            { threshold: 100000, description: 'Construir uma sólida aposentadoria ou garantir o futuro da sua família.', icon: 'fa-solid fa-piggy-bank' },
            { threshold: 200000, description: 'Alcançar a independência financeira e ter mais liberdade de escolha.', icon: 'fa-solid fa-sack-dollar' },
        ];

        let relevantConquests = [];
        allConquests.forEach(conquest => {
            if (totalValue >= conquest.threshold) {
                relevantConquests.push(conquest);
            }
        });

        if (relevantConquests.length === 0 && totalValue < (allConquests[0]?.threshold || 0)) {
            conquestsGrid.innerHTML = `
                <div class="conquest-card no-conquests-yet">
                    <span class="icon fa-solid fa-seedling"></span>
                    <div>
                        <h4>Sua Jornada Começa Aqui!</h4>
                        <p>Continue economizando e logo você verá grandes conquistas!</p>
                    </div>
                </div>
            `;
        } else {
            const displayLimit = 6;
            relevantConquests.sort((a, b) => a.threshold - b.threshold);
            relevantConquests = relevantConquests.slice(Math.max(relevantConquests.length - displayLimit, 0));

            relevantConquests.forEach(conquest => {
                const conquestCard = document.createElement('div');
                conquestCard.classList.add('conquest-card');
                conquestCard.innerHTML = `
                    <span class="icon ${conquest.icon}"></span>
                    <p>${conquest.description}</p>
                `;
                conquestsGrid.appendChild(conquestCard);
            });
        }
    }
});