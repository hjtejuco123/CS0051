
# 🧠 Module 1: Introduction to Sequential, Concurrent, and Parallel Computing

---

## 📘 Learning Objectives
By the end of this module, you will be able to:
- Understand the difference between **Sequential**, **Concurrent**, and **Parallel** computing.
- Write simple C++ programs that demonstrate each concept.
- Explain how real-world tasks relate to computing strategies.

---

## 🧩 Section 1: Sequential Computing

### 💡 What is it?
In **Sequential Computing**, tasks run one after another. There’s only one path of execution.

### 🍔 Real-Life Analogy:
Making a sandwich by yourself:
1. Get bread  
2. Add cheese  
3. Add ham  
4. Assemble sandwich

### 🧪 Code Activity: `makeSandwich`

#### Step-by-step:
```cpp
void makeSandwich() {
    cout << "Step 1: Get bread...\n";
    this_thread::sleep_for(chrono::milliseconds(500)); 
    cout << "Step 2: Add cheese...\n";
    this_thread::sleep_for(chrono::milliseconds(500)); 
    cout << "Step 3: Add ham...\n";
    this_thread::sleep_for(chrono::milliseconds(500)); 
    cout << "Step 4: Assemble the sandwich...\n";
    this_thread::sleep_for(chrono::milliseconds(500)); 
    cout << "Sandwich is ready!\n";
}
```

✅ **Try it Yourself:**  
1. Type and run the code.  
2. Observe the delay between each step.  
3. Modify it by adding a new step (e.g., "Spread butter").

---

## 🧩 Section 2: Concurrent Computing

### 💡 What is it?
Tasks **alternate**, but don't actually run at the same time.

### ☕ Real-Life Analogy:
You toast bread and prepare coffee by alternating between them.

### 🧪 Code Activity: `prepareCoffeeAndToast`

#### Step-by-step:
```cpp
while (coffeeSteps <= 3 || toastSteps <= 3) {
    if (coffeeSteps <= 3) {
        cout << "Preparing coffee - Step " << coffeeSteps << "\n";
        coffeeSteps++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    if (toastSteps <= 3) {
        cout << "Toasting bread - Step " << toastSteps << "\n";
        toastSteps++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
```

✅ **Try it Yourself:**
- Run the code.
- Watch how steps switch between coffee and toast.
- Change the number of steps to see how it affects the flow.

---

## 🧩 Section 3: Parallel Computing

### 💡 What is it?
Tasks run **simultaneously** using multiple threads.

### 🧺 Real-Life Analogy:
You wash dishes while a friend folds clothes at the same time.

### 🧪 Code Activity: `parallelTasks`

#### Step-by-step:
```cpp
thread t1(washDishes);
thread t2(foldClothes);
t1.join(); 
t2.join(); 
```

✅ **Try it Yourself:**
- Run the code.
- Notice how dish-washing and clothes-folding outputs appear interleaved.
- Try replacing one task with a longer task to see what happens.

---

## 🧩 Section 4: Concurrent and Parallel

### 💡 What is it?
Combines both strategies: parts run simultaneously, others switch tasks.

### 🎉 Real-Life Analogy:
At a party:
- You check progress (concurrent)
- Two friends prep food and decorate (parallel)

### 🧪 Code Activity: `organizeParty`

✅ **Try it Yourself:**
- See how your main thread and other threads interact.
- Add a new thread task, e.g., "Playlist setup".

---

## 🧩 Section 5: Sequential vs. Parallel Comparison

### 📦 Real-Life Analogy:
Imagine packing boxes:
- Alone (sequential)
- With help (parallel)

✅ **Discussion Exercise:**
- What are the advantages of using threads?
- When should you stick with sequential logic?

---

## 📝 Knowledge Check: Quick Quiz

1. What’s the main difference between concurrency and parallelism?  
2. Which C++ feature allows running code on multiple threads?  
3. How can we simulate work delays in C++?

---

## 🛠️ Hands-on Challenge

### Scenario:
You are writing a simulation of preparing a school project:
- You gather materials
- Your friend creates slides
- Another friend prints handouts

### 🔧 Your Task:
- Implement this using **parallel computing** with 3 threads.
- Add realistic steps and `sleep_for` delays.
