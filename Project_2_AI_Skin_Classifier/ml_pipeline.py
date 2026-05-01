import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix, accuracy_score

print("Initializing Image-Based ML Pipeline...")

# 1. LOAD THE PIXEL DATASET
# IMPORTANT: Change this filename if yours is spelled slightly differently!
# (Sometimes it is named 'hmnist_28_28_L.csv' or 'hmnist_28_28_RGB.csv')
file_name = 'hmnist_28_28_csv.csv' 
print(f"Loading {file_name}...")
df = pd.read_csv(file_name)

# 2. DATA SPLIT (Pixels vs. Labels)
# In this specific dataset, the last column is usually named 'label' (0-6 for the 7 diseases)
# Everything else is a pixel.
y = df['label']
X = df.drop('label', axis=1)

# 3. TRAIN / TEST SPLIT (80/20)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 4. TRAIN THE BLACK BOX (Optimized for speed)
print("Training the Random Forest on 28x28 image pixels... (Give it about 30 seconds)")
# n_estimators=50 limits the trees so it runs fast on your laptop
model = RandomForestClassifier(n_estimators=50, random_state=42)
model.fit(X_train, y_train)

# 5. ADMINISTER THE TEST
print("Testing the model on hidden images...")
predictions = model.predict(X_test)

# 6. PRINT METRICS
print("\n--- AI Model Performance ---")
print(f"Accuracy Score: {accuracy_score(y_test, predictions) * 100:.2f}%")
print("\n--- Confusion Matrix ---")
print(confusion_matrix(y_test, predictions))

print("\nComputer Vision Pipeline Complete.")