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

function loadData(text) {
    fetch("/get_data/" + text)
        .then(logs => logs.json())
        .then(data => {
            const fileContainer = document.getElementById("logList");
            fileContainer.innerHTML = "";
        
        data.forEach(log => {
            const newDiv = document.createElement("div");
            newDiv.textContent = log;
        })
        })


}

function fetchFiles(){
    fetch('/get_list_of_files')
        .then(files => files.json())
        .then(data => {
            const fileContainer = document.getElementById("fileList");
            fileContainer.innerHTML = "";

        data.forEach(filename => {
            const newDiv = document.createElement("div");
            newDiv.textContent = filename;

            const readBtn = document.createElement("button");
            readBtn.textContent = "View";
            readBtn.onclick = () => {
                window.location.href = "/data_page/" + filename;
                
            }

            const setWriteButton = document.createElement("button");
            setWriteButton.textContent = "Set to Write";
            setWriteButton.onclick = () => {
                fetch('/set_write/' + filename);
            }

            newDiv.appendChild(readBtn);
            newDiv.appendChild(setWriteButton);
            fileContainer.appendChild(newDiv);
        });
        })
}

function addNewFile(){
    fileName = document.getElementById('newFileName').value;
    fetch('/create_file/' + fileName)
        .then(statusCreation => statusCreation.text)
        .then(data => {
            if (data == "OK"){
                alert("File succesfully created ! Reloading the web in 2 seconds !")
                setTimeout(() => {
                    window.location.href = "/data_list";
                }, 2000);
            }
            else if (data == "NO"){
                alert("Failed creating the file !")
            }
            else if (data == "EXIST"){
                alert("File already existed !")
            }
            
        });
}

function toggleCreateFile(){
    const section = document.getElementById("createFileSection");
    if (section.style.display === "none"){
        section.style.display = "block";
    }
    else{
        section.style.display = "none";
    }
}


function cursedWarSpeech(){
    const msg = new SpeechSynthesisUtterance(
        "While fighting in the Kugu Jumo servant - Hungarian war, the G N D and 5 V formed an unholy alliance. striking down a SD Card module that was nurtured from 3 damn A M to 8 A M. Moral: keeps unbroken.");
        msg.lang = 'en-US';
        msg.rate = 0.9;
        speechSynthesis.speak(msg);
    const speech = document.getElementById('warProclamation');
    speech.innerText = "While fighting in the Kugu Jumo servant - Hungarian war, the G N D and 5 V formed an unholy alliance. striking down a SD Card module that was nurtured from 3 damn A M to 8 A M. Moral: keeps unbroken.";
    
    
}
setInterval(fetchData, 5000);
fetchData();