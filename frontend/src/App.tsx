import { useState } from "react";
import { getApiStatus } from "./api/apiClient";

import './App.css'

function App() {
    const [status, setStatus] = useState<string>("Not checked");
    const [isLoading, setIsLoading] = useState(false);

    async function checkApi() {
        try {
            setIsLoading(true);
            setStatus("Checking...");

            const result = await getApiStatus();
            setStatus(result);
        } catch (error) {
            const message = error instanceof Error ? error.message : "Unkown error";

            setStatus(`Connection failed: ${message}`);
        } finally {
            setIsLoading(false);
        }
    }

    return (
        <main>
            <h1>Secure NFC Asset Tracking</h1>

            <section>
                <h2>System status</h2>

                <p>API: {status}</p>

                <button onClick={checkApi} disabled={isLoading}>
                    {isLoading ? "Checking..." : "Check API connection"}
                </button>
            </section>
        </main>
    );
}

export default App
