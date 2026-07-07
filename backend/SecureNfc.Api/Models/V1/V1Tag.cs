namespace SecureNfc.Api.Models.V1
{
    public class V1Tag
    {
        public string Uid { get; set; }
        public string Id { get; set; }
        public string Type { get; set; }
        public string TagVersion { get; set; }
        public string Signature { get; set; }
    }
}