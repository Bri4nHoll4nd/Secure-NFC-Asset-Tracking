const API_BASE_URL = import.meta.env.VITE_API_BASE_URL ?? "http://localhost:5201";

export async function getApiStatus(): Promise<string> {
    const response = await fetch(`${API_BASE_URL}/api/1.0/V1Status`);

    if (!response.ok) {
        throw new Error(`API request failed: ${response.status}`);
    }

    return response.text();
}