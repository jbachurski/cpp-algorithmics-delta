#include <bits/stdc++.h>

using namespace std;

const string pow2[] = {"1", "2", "4", "8", "61", "23", "46", "821", "652", "215", "4201", "8402", "6904", "2918", "48361", "86723", "63556", "270131", "441262", "882425", "6758401", "2517902", "4034914", "8068838", "61277761", "23445533", "46880176", "827712431", "654534862", "219078635", "4281473701", "8463847412", "6927694924", "2954399858", "48196897171", "86383795343", "63767491786", "274359834731", "449609778472", "888318557945", "6777261159901", "2555523209912", "4011156408934", "8022203906978", "61444068129571", "23888027348153", "46677144786307", "823553884737041", "656017679474182", "213124359949265", "4262486099985211", "8425863189971522", "6940737269953054", "2990474529917009", "48918490589341081", "86936981079782063", "63972973049575027", "278558570881511441", "447117151673032882", "884324303257064675", "6796486064051292511", "2593963129003485032", "4097837248106861164", "8085774586302733229", "61615590737044764481", "23230191474188439863", "46460283849267968737", "829214676985259375741", "658528253971509741592", "217156507853018592095", "4243031147170261950811", "8486062284341423811632", "6963125469682846632274", "2937240929375692374449", "48745808587413956498881", "86590716175926813987773", "63191432341952736875557", "272838646828154727511151", "445676392756309454132203", "880353785413708909264406", "6716074719264169185298021", "2532149438529229361587142", "4074288966158548723075384", "8049467933307196556041769", "61889259766043831131824391", "23679509533186672262658683", "46259118176263355425217377", "825093263435276019405247451", "650187427860543128900584903", "211265944731096246910079816", "4224219984720835829300497321", "8448428979450670758700885742", "6986946959901251417510671594", "2973992919912403824130253099", "48578958389348066582604070891", "86157917769786123175218041693", "63305934539573346241526182297", "276009780781576825820523654851", "443108571473053750750056219613", "886206153847007411411003528336", "6735023076941049228220060567621", "2570146043992088546540021035352", "4051282186895067192190042060705", "80034652637911253852810840214101", "61068215274932407615630690428202", "23027520549874804330370291846504", "46044150098759618660641483692118", "821882010875193363312928672952261", "652675020651387627624856355815423", "215251140213665354358613701730946", "4205032804262317096073364124708921", "8400164618425624183147629248416952", "6900229236940358267284358586922915", "29104485629906075255696071739548301", "48308861358912141501393143478196702", "86706733607934282012687286847383514", "63512576214978465024275563794767038", "270340535288579211484411374994351661", "441680070567159522869822649899603233", "882271041035309154639754298799316466", "6754430820607083092785194875997229231", "2519860650214167085471389651995548562", "4038731211428225161943669313891196135", "80665724228465403238962397266932833601", "61231558446921906466935685523974676212", "23462017982952812923970371156859253524", "46825024975815634856851643203719507058", "827501488517303786137132964064381141071", "654112867134706473364364839029663282043", "219224635368412947629629678148337465086", "4285482707279248943583583573867649211631", "8461965414549586996077077057635398522272", "6923831928098173993145145105370787154445", "29566728561873478972803803007414753098801", "48133556133657847955616616004928417087712", "86366013366215794911332332108856924165534", "63723126623520599832664664206713958221178", "274562423560500997742392394025368175422471", "449035846031010895594685689040727341944843", "888160792162020691199271379180454782898696", "6773214952250402932895436493618094756973931", "2557428815401804874691962987236189413957872", "4015946730902618659293835875562369926815755", "80209925708142363195876707511356299527305111", "61408950516384627281753514132603589154700322", "23806911032769254563417038264216079309410644", "46612932064439509037824166529422149708920298", "823348740298681181647582231589442885169504871", "656686590487373263294175462079984671329118653", "213373191865747427489241925049979253648326317", "4266472836315949449695828501889595072967427241", "8423945672720998988391756112679191145835944582", "6946890355450897977783413324259383280770998075", "29927916019016959555778266484097674614518971411", "48954932128122919111557523969085359238036953822", "86919874246344838322015156839161709566162917654", "63938759482788676744020303778323418133325834319", "278765199654773535980406064577468263666407786281", "447531389319457070971802129055927527233904573563", "884172669728905141853614248101954154566818057037", "6792452395569103826172384863028192090337361051641", "2595805681139306652345669637046385081664723003292", "4091710373268702315680339374182761163239456006485", "80834306474275146203716687492654332274689031029611", "61678602949441382506432375985219664449279162048332", "23257314898982665012964641971528339888549325086764", "46405728697975231124839292853056768777198740163539", "829005563959515622486785856170035375553875902270781", "658100137819130354863571713341060741117651914441473", "217300264738360609637053436682021492224313838882847", "4247004294767212183741078623750428854486266767756941", "8484108489435524267492047356411846719863523535513992", "6969206969960158425985084703922692538737056070136895", "29395029399312079409711694168542950765741031412627911", "48781148789724049908532299227194811431592062824254932", "86573286579558088916174489544389632862095025658409874", "63157463159117167932349869198669374635081140317908759", "272059272093243259746887393873397492701632806249165191", "445009545087486409592775787657685985412274612588321383", "880108190165963908195451575315371971924449234077742667", "6712063812219378163819030517207438538588885680455942351", "2534027634428747327638160034504966176177771371801994603", "4078044378846594744376321068018833343345553643612899216", "80471886477921994986437420271267766866801172962346995221", "61843673945952899873964940443425533733712245835682991542", "23696257890915699757839890886840176476434480770375893094", "46293505791830399515778791673790243943968861451641797089", "825870105936706891305575932574914868968377338032924951691", "650751200972512793600151974059838637937745766164858813293", "211413400855034497210203859009776374974590533329617736487", "4228268006111688855204066191085537498590910766483345729651", "8446527102322277711508023383061174987191830433967680558313", "6982154304644445532016146667023249875383670866835371017726", "29752096082988801740223823351464887517672516337707430245521", "48515083165877712490446656603829675134355032764514960480152", "86130167221755534881882313316658351368601164439038831861205", "633602255424111786736756266223177036273122298681667726334001", "276214401948222473572513523546245162547244487373235552768002", "443528802896544847055036056092580325094588865747460115437104", "886056714693198694101162103185071640189077731594921220964308"};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n, m, s, t, k;
    cin >> n >> m >> s >> t >> k;
    s--; t--;

    vector<size_t> type(n);
    for(auto& a : type)
        cin >> a;

    vector<vector<size_t>> graph(n);
    for(size_t i = 0; i < m; i++)
    {
        size_t u, v;
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> vis(n), lock(k);
    function<void(size_t)> dfs = [&](size_t u) {
        if(vis[u]) return;
        vis[u] = true;
        for(auto v : graph[u])
            if(not lock[type[v]])
                dfs(v);
    };
    auto reach = [&]() -> bool {
        if(lock[type[s]])
            return false;
        fill(vis.begin(), vis.end(), false);
        dfs(s);
        return vis[t];
    };

    for(size_t l = k; l --> 0; )
    {
        lock[l] = true;
        if(not reach())
            lock[l] = false;
    }

    vector<int> digits(pow2[k-1].size() + 0xD);
    for(size_t l = 0; l < k; l++)
        if(not lock[l])
            for(size_t i = 0; i < pow2[l].size(); i++)
                digits[i] += pow2[l][i] - '0';
    for(size_t i = 0; i+1 < digits.size(); i++)
        digits[i+1] += digits[i] / 10, digits[i] %= 10;
    while(not digits.empty() and not digits.back())
        digits.pop_back();
    for(size_t i = digits.size(); i --> 0; )
        cout << digits[i];
    cout << endl;
}