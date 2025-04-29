<!--
# 🧠 Module 1: Introduction to Sequential, Concurrent, and Parallel Computing

## 📘 Learning Objectives
- Understand the difference between **Sequential**, **Concurrent**, and **Parallel** computing.
- Write simple C++ programs that demonstrate each concept.
- Explain how real-world tasks relate to computing strategies.

---

## 🧬 Section 1: Sequential Computing

### 💡 What is it?
Sequential Computing runs tasks one after another — only one path of execution.

### 🍔 Real-Life Analogy
Making a sandwich by yourself:
1. Get bread
2. Add cheese
3. Add ham
4. Assemble sandwich

### 🧪 Code Activity: `makeSandwich`

#### Questions for Students:
- What do you observe when you run the sequential sandwich-making code?  
  **Answer:** ___________

- If you were to add "Spread butter" before adding cheese, how would you modify the steps?  
  **Answer:** ___________

- Why is sequential execution important in some programs?  
  **Answer:** ___________

---

## 🧬 Section 2: Concurrent Computing

### 💡 What is it?
Tasks **alternate**, but don't actually run at the same time.

### ☕ Real-Life Analogy
Alternating between making coffee and toasting bread.

### 🧪 Code Activity: `prepareCoffeeAndToast`

#### Questions for Students:
- What pattern did you notice when the coffee and toast preparation alternated?  
  **Answer:** ___________

- How did changing the number of steps affect the alternation?  
  **Answer:** ___________

- Give a real-life example (other than coffee and toast) that could be done concurrently.  
  **Answer:** ___________

---

## 🧬 Section 3: Parallel Computing

### 💡 What is it?
Tasks run **simultaneously** using multiple threads.

### 🪣 Real-Life Analogy
You wash dishes while a friend folds clothes at the same time.

### 🧪 Code Activity: `parallelTasks`

#### Questions for Students:
- How did the outputs of dish-washing and clothes-folding appear?  
  **Answer:** ___________

- What happened when one of the tasks took longer than the other?  
  **Answer:** ___________

- Why is parallel computing useful?  
  **Answer:** ___________

---

## 🧬 Section 4: Concurrent and Parallel

### 💡 What is it?
Combines both strategies: parts run simultaneously, others switch tasks.

### 🎉 Real-Life Analogy
At a party:
- You check progress (concurrent)
- Two friends prep food and decorate (parallel)

### 🧪 Code Activity: `organizeParty`

#### Questions for Students:
- How did the main thread interact with the other threads?  
  **Answer:** ___________

- If you add a new task "Playlist setup," how will it affect the party preparation?  
  **Answer:** ___________

- Give another real-world scenario that involves both concurrency and parallelism.  
  **Answer:** ___________

---

## 🧬 Section 5: Sequential vs. Parallel Comparison

### 📦 Real-Life Analogy
Packing boxes:
- Alone (sequential)
- With help (parallel)

#### Questions for Students:
- What are the advantages of using threads compared to sequential packing?  
  **Answer:** ___________

- When is it better to use sequential execution instead of parallel execution?  
  **Answer:** ___________

---

## 📝 Knowledge Check: Quick Quiz

Answer the following questions:

- What’s the main difference between concurrency and parallelism?  
  **Answer:** ___________

- Which C++ feature allows running code on multiple threads?  
  **Answer:** ___________

- How can we simulate work delays in C++?  
  **Answer:** ___________

---

## 🛠️ Hands-on Challenge

### Scenario:
You are simulating preparation for a school project:
- You gather materials
- Your friend creates slides
- Another friend prints handouts

#### Questions for Students:
- How will you implement this simulation using parallel computing with 3 threads?  
  **Answer:** ___________

- List down realistic steps you would add, and how you would insert delays.  
  **Answer:** ___________

- Sketch a simple plan on how you would divide tasks among threads.  
  **Answer:** ___________

---

# 🔢 Final Programming Task: Combine All Concepts

## Programming Activity
- Create a single C++ program containing a **menu system**.
- The menu should allow users to select:
  1. Sequential Sandwich Making
  2. Concurrent Coffee and Toast Preparation
  3. Parallel Dishwashing and Clothes Folding
  4. Concurrent and Parallel Party Organization
- Each menu item should call the respective program section.
- Use threads where necessary.
- Comment the code to explain how each technique is implemented.

### Sample Menu Layout
```
Select an activity:
1. Make a Sandwich (Sequential)
2. Prepare Coffee and Toast (Concurrent)
3. Perform House Chores (Parallel)
4. Organize a Party (Concurrent and Parallel)
5. Exit
```

---

# 💬 End of Module 1

Congratulations! Reflect on what you learned before moving to the next module.
-->


