const hamMenu = document.querySelector('.hamburger-button');

const offScreenMenu = document.querySelector('.off-screen-menu');

hamMenu.addEventListener('click', () => {
    hamMenu.classList.toggle('active');
        offScreenMenu.classList.toggle('active');
});

function fetchData(){
    fetch('/get_esp32_data')
        .then(response => response.json())
        .then(data => {
            document.getElementById('temp').innerText = data.temp;
            document.getElementById('humidity').innerText = data.humidity;
            document.getElementById('tds').innerText= data.tds;
            document.getElementById('pH').innerText = data.pH;
            document.getElementById('need-refil').innerText = data.Need_refil;
            document.getElementById('voltage-tds').innerText = data.voltageTDS;
            document.getElementById('rawvalue-ph').innerText = data.rawValuePH;
            document.getElementById('voltage-ph').innerText = data.voltagePH;
        })
        .catch(err => console.error('Fetch Failed',err));    
}

setInterval(fetchData, 5000);
fetchData();