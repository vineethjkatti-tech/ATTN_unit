document.addEventListener('DOMContentLoaded', () => {
    const bulbContainer = document.getElementById('bulb-container');
    const toggleBtn = document.getElementById('toggle-btn');
    const typeBtns = document.querySelectorAll('.type-btn');

    let isOn = false;
    let currentType = 'standard';

    // Toggle Power
    toggleBtn.addEventListener('click', () => {
        isOn = !isOn;
        if (isOn) {
            bulbContainer.classList.remove('off');
            bulbContainer.classList.add('on');
            toggleBtn.textContent = 'Power: ON';
            toggleBtn.style.backgroundColor = '#555';
            toggleBtn.style.color = '#ffeb3b';
        } else {
            bulbContainer.classList.remove('on');
            bulbContainer.classList.add('off');
            toggleBtn.textContent = 'Power: OFF';
            toggleBtn.style.backgroundColor = '#333';
            toggleBtn.style.color = 'white';
        }
    });

    // Switch Bulb Type
    typeBtns.forEach(btn => {
        btn.addEventListener('click', () => {
            const type = btn.getAttribute('data-type');

            // Update UI
            typeBtns.forEach(b => b.classList.remove('active'));
            btn.classList.add('active');

            // Update Bulb
            bulbContainer.classList.remove(`bulb-${currentType}`);
            currentType = type;
            bulbContainer.classList.add(`bulb-${currentType}`);
        });
    });
});
