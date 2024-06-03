document.addEventListener('DOMContentLoaded', () => {
    const taskInput = document.getElementById('new-task');
    const addTaskBtn = document.getElementById('add-task-btn');
    const taskList = document.getElementById('task-list');

    addTaskBtn.addEventListener('click', addTask);
    taskInput.addEventListener('keypress', function(e) {
        if (e.key === 'Enter') {
            addTask();
        }
    });

    function addTask() {
        const taskText = taskInput.value.trim();
        if (taskText !== '') {
            const taskItem = document.createElement('li');
            taskItem.classList.add('task-item');
            taskItem.innerHTML = `
                <span>${taskText}</span>
                <button onclick="removeTask(this)">Remove</button>
            `;
            taskList.appendChild(taskItem);
            taskInput.value = '';
        }
    }
});

function removeTask(button) {
    const taskItem = button.parentElement;
    taskItem.remove();
}
