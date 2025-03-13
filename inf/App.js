import React, { useState } from 'react';

function App() {
  const [letterInput, setLetterInput] = useState('');
  const [numberInput, setNumberInput] = useState('');

  const handleLetterChange = (event) => {
    const value = event.target.value.toUpperCase();
    if (/^[A-Z]$/.test(value)) {
      setLetterInput(value);
    }
  };

  const handleNumberChange = (event) => {
    const value = event.target.value;
    if (/^[0-9]$/.test(value)) {
      setNumberInput(value);
    }
  };

  const handleClearInputs = () => {
    setLetterInput('');
    setNumberInput('');
  };

  const handleShowValues = () => {
    if (letterInput && numberInput) {
      alert(`Letter input value: ${letterInput}\nNumber input value: ${numberInput}`);
    } else {
      alert('Please enter valid values for both inputs.');
    }
  };

  return (
    <div>
      <input
        type="text"
        placeholder="Enter a letter (A-Z)"
        value={letterInput}
        onChange={handleLetterChange}
      />
      <input
        type="text"
        placeholder="Enter a number (0-9)"
        value={numberInput}
        onChange={handleNumberChange}
      />
      <button onClick={handleClearInputs}>Clear Inputs</button>
      <button onClick={handleShowValues}>Show Values</button>
    </div>
  );
}

export default App;
