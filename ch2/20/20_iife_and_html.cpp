#include <iostream>
#include <string>

void
validateHTML(const std::string &)
{
}

std::string
buildAHref(const std::string &link, const std::string &text)
{
    // IIFE to initialize a complex const value
    const std::string html = [&link, &text] {
        const auto &inText = text.empty() ? link : text;
        return "<a href=\"" + link + "\">" + inText + "</a>";
    }();

    validateHTML(html);

    return html;
}

int
main()
{
    try
    {
        const auto ahref = buildAHref("www.leanpub.com", "Leanpub Store");
        std::cout << ahref; // <a href="www.leanpub.com">Leanpub Store</a>
    }
    catch (...)
    {
        std::cout << "bad format...";
    }
}
